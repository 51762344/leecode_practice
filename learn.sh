#!/bin/bash

set -euo pipefail

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

usage() {
  echo -e "${YELLOW}用法: ./solve.sh [题目编号]${NC}"
  echo -e "${YELLOW}示例: ./solve.sh 15${NC}"
  echo ""
  echo -e "${BLUE}可用的题目:${NC}"
  for test_file in tests/[0-9]*.cpp; do
    if [ -f "$test_file" ]; then
      num=$(basename "$test_file" | grep -o '^[0-9]\+')
      title=$(grep "题目名称:" "$test_file" | head -1 | sed 's/.*题目名称: //')
      echo -e "  ${GREEN}$num${NC} - $title"
    fi
  done
}

if [ $# -eq 0 ]; then
  usage
  exit 0
fi

PROBLEM_NUM=$(printf "%03d" $((10#$1)))
TEST_FILE=$(ls tests/${PROBLEM_NUM}_*.cpp 2>/dev/null | head -1 || true)

if [ -z "${TEST_FILE}" ] || [ ! -f "${TEST_FILE}" ]; then
  echo -e "${RED}✗ 错误: 找不到测试文件 tests/${PROBLEM_NUM}_*.cpp${NC}"
  echo ""
  usage
  exit 1
fi

TITLE=$(grep "题目名称:" "$TEST_FILE" | head -1 | sed 's/.*题目名称: //')
DIFFICULTY=$(grep "难度:" "$TEST_FILE" | head -1 | sed 's/.*难度: //')

echo -e "${YELLOW}================================${NC}"
echo -e "${YELLOW}  Solve $PROBLEM_NUM: $TITLE ($DIFFICULTY)${NC}"
echo -e "${YELLOW}================================${NC}"

# 保存当前题目编号（run.sh 不传参时会读取它）
echo "$PROBLEM_NUM" > .current_problem

# 1) 提取题目描述（文件开头第一个注释块）
PROBLEM_DESC=$(sed -n '1,/^[[:space:]]*\*\/[[:space:]]*$/p' "$TEST_FILE")

# 2) 提取函数签名（后备方案，用于无法抽取参考解法时）
FUNC_SIG=$(sed -n '/@Solution/,/@EndSolution/p' "$TEST_FILE" \
  | grep -v "@" \
  | grep -v "class Solution" \
  | grep -v "};" \
  | grep -v "public:" \
  | sed 's/;//' \
  | xargs || true)

if [ -z "${FUNC_SIG}" ]; then
  # 再兜底一次：从 class Solution 附近抓一行
  FUNC_SIG=$(grep -A 3 "class Solution" "$TEST_FILE" | tail -1 | sed 's/;//' | xargs || true)
fi

if [ -z "${FUNC_SIG}" ]; then
  FUNC_SIG="// TODO: 实现你的解法"
fi

# 3) 从“解题思路”的注释里抽取第一份可用参考解法（class Solution {...};）
#    说明：只取第一份 class Solution，避免把多个版本都塞进 template.cpp 导致重定义。
EXTRACTED_SOLUTION=$(awk '
  BEGIN { ref=0; in_class=0; depth=0; started=0 }
  /参考解法/ { ref=1 }
  {
    if (!ref) next;

    line = $0;
    # 只在注释段里抓（一般以 " * " 开头）
    if (line !~ /^[[:space:]]*\*/) next;

    s = line;
    sub(/^[[:space:]]*\*[[:space:]]?/, "", s);

    if (!in_class) {
      if (s ~ /^class[[:space:]]+Solution[[:space:]]*\{/) {
        in_class = 1;
      } else {
        next;
      }
    }

    print s;

    tmp = s;
    ob = gsub(/\{/, "", tmp);
    tmp = s;
    cb = gsub(/\}/, "", tmp);
    depth += ob - cb;

    if (!started && ob > 0) started = 1;

    if (started && depth <= 0) {
      exit;
    }
  }
' "$TEST_FILE" || true)

# 4) 提取“解题思路”整段注释（用于追加到 template.cpp，方便复习）
THOUGHT_BLOCK=$(awk '
  BEGIN { start=0; prev="" }
  {
    if (!start && $0 ~ /====================[[:space:]]*解题思路[[:space:]]*====================/) {
      if (prev ~ /^\/\*[[:space:]]*$/) print prev;
      print $0;
      start = 1;
      next;
    }
    if (start) print $0;
    prev = $0;
  }
' "$TEST_FILE" || true)

# 5) 生成 template.cpp（题目描述 + 可编译解法 + 思路注释）
{
  echo "$PROBLEM_DESC"
  echo ""
  echo '#include "leetcode_framework.h"'
  echo ""
  echo "// ==================== 在下方编写你的解法 ===================="
  echo ""

  if [ -n "${EXTRACTED_SOLUTION}" ]; then
    echo "$EXTRACTED_SOLUTION"
  else
    echo -e "${YELLOW}⚠ 未能从思路中抽取参考解法，将生成函数签名骨架。${NC}" 1>&2
    echo "class Solution {"
    echo "public:"
    echo "    ${FUNC_SIG} {"
    echo "        // 在这里编写你的代码"
    echo "        "
    echo "    }"
    echo "};"
  fi

  if [ -n "${THOUGHT_BLOCK}" ]; then
    echo ""
    echo "$THOUGHT_BLOCK"
  fi
} > template.cpp

echo -e "${GREEN}✓ template.cpp 已更新（包含可运行解法 + 解题思路）${NC}"

echo ""
echo -e "${BLUE}ℹ 现在开始运行测试...${NC}"

# 6) 直接运行该题测试
./run.sh "$PROBLEM_NUM"
