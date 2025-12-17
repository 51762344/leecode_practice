#!/bin/bash

# 题目切换辅助脚本

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

if [ $# -eq 0 ]; then
    echo -e "${YELLOW}当前可用题目:${NC}"
    echo ""
    for test_file in tests/[0-9]*.cpp; do
        if [ -f "$test_file" ]; then
            num=$(basename "$test_file" | grep -o '^[0-9]\+')
            title=$(grep "题目名称:" "$test_file" | head -1 | sed 's/.*题目名称: //')
            difficulty=$(grep "难度:" "$test_file" | head -1 | sed 's/.*难度: //')
            
            # 检查是否是当前题目
            current=""
            if [ -f ".current_problem" ] && [ "$(cat .current_problem)" = "$num" ]; then
                current=" ${GREEN}[当前]${NC}"
            fi
            
            echo -e "  ${BLUE}$num${NC} - $title ($difficulty)$current"
        fi
    done
    echo ""
    echo -e "${YELLOW}使用方法: ./switch.sh [题目编号]${NC}"
    echo -e "${YELLOW}示例: ./switch.sh 001${NC}"
    exit 0
fi

PROBLEM_NUM=$(printf "%03d" $((10#$1)))
# 查找对应的测试文件（支持新的命名格式）
TEST_FILE=$(ls tests/${PROBLEM_NUM}_*.cpp 2>/dev/null | head -1)

if [ -z "$TEST_FILE" ] || [ ! -f "$TEST_FILE" ]; then
    echo -e "${RED}✗ 错误: 找不到题目 $PROBLEM_NUM${NC}"
    exit 1
fi

# 获取题目信息
TITLE=$(grep "题目名称:" "$TEST_FILE" | head -1 | sed 's/.*题目名称: //')
DIFFICULTY=$(grep "难度:" "$TEST_FILE" | head -1 | sed 's/.*难度: //')

echo -e "${GREEN}✓ 切换到题目 $PROBLEM_NUM: $TITLE${NC}"
echo -e "  难度: $DIFFICULTY"
echo ""

# 保存当前题目编号
echo "$PROBLEM_NUM" > .current_problem

# 提取函数签名
# 从 @Solution 块中读取
FUNC_SIG=$(sed -n '/@Solution/,/@EndSolution/p' "$TEST_FILE" | grep -v "@" | grep -v "class Solution" | grep -v "};" | grep -v "public:" | sed 's/;//' | xargs)

if [ -z "$FUNC_SIG" ]; then
    # 尝试旧方法作为后备
    FUNC_SIG=$(grep -A 2 "class Solution" "$TEST_FILE" | tail -1 | sed 's/;//' | xargs)
fi

if [ -z "$FUNC_SIG" ]; then
    echo -e "${YELLOW}⚠ 无法自动提取函数签名${NC}"
    FUNC_SIG="// TODO: 实现你的解法"
fi

# 打印提示
echo -e "${BLUE}ℹ 函数签名: $FUNC_SIG${NC}"

# 提取测试文件中的题目描述（从开头到第一个 */）
PROBLEM_DESC=$(sed -n '1,/^ \*\/$/p' "$TEST_FILE")

# 更新 template.cpp
{
    echo "$PROBLEM_DESC"
    echo ""
    echo '#include "leetcode_framework.h"'
    echo ""
    echo "// ==================== 在下方编写你的解法 ===================="
    echo ""
    echo "class Solution {"
    echo "public:"
    echo "    $FUNC_SIG {"
    echo "        // 在这里编写你的代码"
    echo "        "
    echo "    }"
    echo "};"
} > template.cpp

echo -e "${BLUE}ℹ template.cpp 已更新${NC}"
echo -e "${YELLOW}现在可以运行: ./run.sh${NC}"
