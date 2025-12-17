#!/bin/bash

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 默认题目编号
PROBLEM_NUM=""

# 解析命令行参数
if [ $# -eq 0 ]; then
    # 没有参数，尝试读取配置文件
    if [ -f ".current_problem" ]; then
        PROBLEM_NUM=$(cat .current_problem)
        echo -e "${BLUE}ℹ 使用配置文件中的题目: $PROBLEM_NUM${NC}"
    else
        # 列出可用的测试文件
        echo -e "${YELLOW}使用方法: ./run.sh [题目编号]${NC}"
        echo ""
        echo -e "${BLUE}可用的题目:${NC}"
        for test_file in tests/[0-9]*.cpp; do
            if [ -f "$test_file" ]; then
                num=$(basename "$test_file" | grep -o '^[0-9]\+')
                title=$(grep "题目名称:" "$test_file" | head -1 | sed 's/.*题目名称: //')
                echo -e "  ${GREEN}$num${NC} - $title"
            fi
        done
        echo ""
        echo -e "${YELLOW}示例: ./run.sh 009${NC}"
        echo -e "${YELLOW}或者: 创建 .current_problem 文件指定默认题目${NC}"
        exit 0
    fi
else
    PROBLEM_NUM=$(printf "%03d" $((10#$1)))
fi

# 查找对应的测试文件（支持新的命名格式）
TEST_FILE=$(ls tests/${PROBLEM_NUM}_*.cpp 2>/dev/null | head -1)

if [ -z "$TEST_FILE" ] || [ ! -f "$TEST_FILE" ]; then
    echo -e "${RED}✗ 错误: 找不到测试文件 tests/${PROBLEM_NUM}_*.cpp${NC}"
    echo -e "${YELLOW}可用的题目:${NC}"
    for test_file in tests/[0-9]*.cpp; do
        if [ -f "$test_file" ]; then
            num=$(basename "$test_file" | grep -o '^[0-9]\+')
            echo "  - $num"
        fi
    done
    exit 1
fi

# 显示题目信息
TITLE=$(grep "题目名称:" "$TEST_FILE" | head -1 | sed 's/.*题目名称: //')
echo -e "${YELLOW}================================${NC}"
echo -e "${YELLOW}  题目 $PROBLEM_NUM: $TITLE${NC}"
echo -e "${YELLOW}================================${NC}"
echo ""

# 编译
echo -e "${YELLOW}[编译中...]${NC}"
# 只编译测试文件，因为它已经 include 了 template.cpp
g++ -std=c++17 -Wall -Wextra "$TEST_FILE" -o template_run

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ 编译成功！${NC}"
    echo ""
    echo -e "${YELLOW}================================${NC}"
    echo -e "${YELLOW}  运行测试${NC}"
    echo -e "${YELLOW}================================${NC}"
    echo ""
    
    # 运行程序
    ./template_run
    
    # 清理可执行文件
    rm -f template_run
else
    echo -e "${RED}✗ 编译失败！请检查代码。${NC}"
    exit 1
fi
