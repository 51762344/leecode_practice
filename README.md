# 🚀 LeetCode 刷题框架

> 本地 LeetCode 刷题环境  
> 适合在实验室/上班不干正事时刷题 🐶

## 🚀 快速开始

### 环境要求

- C++17 或更高版本
- g++ 编译器
- Bash shell

### 基本使用

```bash
# 1. 切换到某个题目（例如：两数之和）
./switch.sh 1

# 2. 在 template.cpp 中编写你的解法

# 3. 运行测试
./run.sh

# 4. （可选）直接查看答案和思路
./learn.sh 1
```

### 查看所有题目

```bash
./switch.sh  # 列出所有可用题目
```

## 📁 项目结构

```
algo/
├── template.cpp           # 当前题目的工作文件（在这里写解法）
├── leetcode_framework.h   # 测试框架核心
├── switch.sh              # 题目切换工具
├── run.sh                 # 测试运行工具
├── learn.sh               # 答案查看工具
├── tests/                 # 题目库（包含题目、测试用例、题解）
│   ├── 001_两数之和.cpp
│   ├── 009_回文数.cpp
│   └── ...
└── README.md
```

## 💡 使用示例

```bash
# 切换到题目 9（回文数）
./switch.sh 9

# 在 template.cpp 中实现你的解法
# ...编码中...

# 测试你的代码
./run.sh

# 输出：
# ✓ 测试通过: 测试用例 1
# ✓ 测试通过: 测试用例 2
# 🎉 恭喜！所有测试都通过了！
```

```bash
# 直接查看题目 15 的参考解法和思路
./learn.sh 15

# template.cpp 会自动填充参考答案
# 同时运行测试，验证解法的正确性
```

## 🙏 致谢

- 题目来源：[LeetCode](https://leetcode.cn/)

---

**Happy Coding!** 💻✨
