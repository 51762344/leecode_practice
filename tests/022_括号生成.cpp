/*
 * 题目编号: 022
 * 题目名称: 括号生成
 * 难度: 中等
 * 
 * 题目描述:
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 示例 1：
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 示例 2：
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 提示：
 * - 1 <= n <= 8
 */

/*
@Solution
class Solution {
public:
    vector<string> generateParenthesis(int n);
};
@EndSolution
*/

#include "../leetcode_framework.h"

#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [022. 括号生成]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<string> expected1 = {"((()))","(()())","(())()","()(())","()()()"};
    vector<string> result1 = solution.generateParenthesis(3);
    sort(result1.begin(), result1.end());
    sort(expected1.begin(), expected1.end());
    RUN_TEST(result1, expected1, "测试用例 1: n=3");
    
    // 测试用例 2
    vector<string> expected2 = {"()"};
    RUN_TEST(solution.generateParenthesis(1), expected2, "测试用例 2: n=1");
    
    // 测试用例 3
    vector<string> expected3 = {"(())", "()()"};
    vector<string> result3 = solution.generateParenthesis(2);
    sort(result3.begin(), result3.end());
    sort(expected3.begin(), expected3.end());
    RUN_TEST(result3, expected3, "测试用例 3: n=2");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的**回溯**问题，面试超高频（字节、腾讯、阿里必考）。
 * 
 * 核心思想：
 * 使用回溯法生成所有可能的括号组合，需要满足：
 * 1. 左括号数量不超过 n
 * 2. 右括号数量不超过左括号数量
 * 3. 最终左右括号数量都等于 n
 * 
 * 【算法步骤】
 * 1. 使用回溯函数，维护当前字符串和左右括号数量
 * 2. 如果左括号数量 < n，可以添加左括号
 * 3. 如果右括号数量 < 左括号数量，可以添加右括号
 * 4. 当字符串长度达到 2n 时，加入结果集
 * 
 * 【参考解法】
 * 
 * // 方法1：回溯（标准解法）
 * class Solution {
 * public:
 *     vector<string> generateParenthesis(int n) {
 *         vector<string> result;
 *         string current;
 *         backtrack(result, current, 0, 0, n);
 *         return result;
 *     }
 *     
 * private:
 *     void backtrack(vector<string>& result, string& current, 
 *                   int left, int right, int n) {
 *         // 终止条件：生成了完整的括号组合
 *         if (current.length() == 2 * n) {
 *             result.push_back(current);
 *             return;
 *         }
 *         
 *         // 可以添加左括号
 *         if (left < n) {
 *             current.push_back('(');
 *             backtrack(result, current, left + 1, right, n);
 *             current.pop_back();  // 回溯
 *         }
 *         
 *         // 可以添加右括号
 *         if (right < left) {
 *             current.push_back(')');
 *             backtrack(result, current, left, right + 1, n);
 *             current.pop_back();  // 回溯
 *         }
 *     }
 * };
 * 
 * // 方法2：回溯（另一种写法）
 * class Solution {
 * public:
 *     vector<string> generateParenthesis(int n) {
 *         vector<string> result;
 *         backtrack(result, "", n, n);
 *         return result;
 *     }
 *     
 * private:
 *     void backtrack(vector<string>& result, string current, 
 *                   int left, int right) {
 *         // 终止条件
 *         if (left == 0 && right == 0) {
 *             result.push_back(current);
 *             return;
 *         }
 *         
 *         // 还有左括号可以添加
 *         if (left > 0) {
 *             backtrack(result, current + "(", left - 1, right);
 *         }
 *         
 *         // 右括号剩余数量 > 左括号，可以添加右括号
 *         if (right > left) {
 *             backtrack(result, current + ")", left, right - 1);
 *         }
 *     }
 * };
 * 
 * 【复杂度分析】
 * - 时间复杂度：O(4^n / √n) - 第 n 个卡特兰数，约为 4^n / √n
 * - 空间复杂度：O(n) - 递归调用栈的深度
 * 
 * 【关键点】
 * 
 * 1. **回溯的剪枝条件**：
 *    - 左括号数量不能超过 n
 *    - 右括号数量不能超过左括号数量
 *    - 这样可以保证生成的都是有效括号
 * 
 * 2. **为什么 right < left**：
 *    - 任何时候，已使用的右括号数不能超过左括号数
 *    - 否则会出现 ")(" 这样的无效情况
 * 
 * 3. **回溯的核心**：
 *    - 做选择：添加括号
 *    - 递归：继续生成后续括号
 *    - 撤销选择：pop_back() 或使用不同的字符串
 * 
 * 4. **两种实现方式**：
 *    - 方法1：记录已使用的左右括号数量（从0开始）
 *    - 方法2：记录剩余的左右括号数量（从n开始）
 *    - 本质相同，只是计数方向不同
 * 
 * 【图解示例】
 * n = 2 的回溯树：
 * 
 *                    ""
 *                   /
 *                 "("
 *               /    \
 *            "(("     "()"
 *             |      /   \
 *          "(())"  "()(" "()"
 *                   |      |
 *                "()())"   ...
 * 
 * 有效路径：
 * - "" → "(" → "((" → "(()" → "(())" ✓
 * - "" → "(" → "()" → "()(" → "()()" ✓
 * 
 * 无效路径（被剪枝）：
 * - ")..." (right > left，不合法)
 * 
 * 【回溯模板】
 * ```
 * void backtrack(参数) {
 *     if (终止条件) {
 *         收集结果;
 *         return;
 *     }
 *     
 *     for (选择 : 选择列表) {
 *         做选择;
 *         backtrack(参数);
 *         撤销选择;
 *     }
 * }
 * ```
 * 
 * 【面试高频程度】⭐⭐⭐⭐⭐
 * - 字节跳动：超高频
 * - 腾讯：高频
 * - 阿里：高频
 * - 美团：高频
 * 
 * 【相关题目】
 * - LeetCode 20: 有效的括号（栈）
 * - LeetCode 32: 最长有效括号（动态规划）
 * - LeetCode 301: 删除无效的括号（BFS/回溯）
 * 
 * 【面试技巧】
 * 1. 先说清楚回溯的思路和剪枝条件
 * 2. 画出回溯树帮助理解
 * 3. 解释为什么 right < left
 * 4. 这是学习回溯的最佳题目之一
 */

