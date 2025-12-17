/*
 * 题目编号: 20
 * 题目名称: 有效的括号
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 1. 左括号必须用相同类型的右括号闭合。
 * 2. 左括号必须以正确的顺序闭合。
 * 3. 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 示例 1:
 * 输入: s = "()"
 * 输出: true
 * 
 * 示例 2:
 * 输入: s = "()[]{}"
 * 输出: true
 * 
 * 示例 3:
 * 输入: s = "(]"
 * 输出: false
 * 
 * 提示:
 * - 1 <= s.length <= 10^4
 * - s 仅由括号 '()[]{}' 组成
 */

/*
@Solution
class Solution {
public:
    bool isValid(string s);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [20. 有效的括号]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    RUN_TEST(solution.isValid("()"), true, "测试用例 1: ()");
    
    // 测试用例 2
    RUN_TEST(solution.isValid("()[]{}"), true, "测试用例 2: ()[]{}");
    
    // 测试用例 3
    RUN_TEST(solution.isValid("(]"), false, "测试用例 3: (]");
    
    // 测试用例 4
    RUN_TEST(solution.isValid("([)]"), false, "测试用例 4: ([)]");
    
    // 测试用例 5
    RUN_TEST(solution.isValid("{[]}"), true, "测试用例 5: {[]}");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 判断括号字符串是否有效，典型的栈（Stack）应用场景。
 * 
 * 核心思路：
 * 1. 遇到左括号，压入栈中
 * 2. 遇到右括号，检查栈顶是否是匹配的左括号
 * 3. 最后栈应该为空
 * 
 * 【算法步骤】
 * 1. 创建一个栈
 * 2. 遍历字符串：
 *    - 如果是左括号 '(', '[', '{'，压入栈
 *    - 如果是右括号：
 *      * 如果栈为空，返回 false（没有匹配的左括号）
 *      * 如果栈顶不匹配，返回 false
 *      * 否则弹出栈顶
 * 3. 遍历完成后，检查栈是否为空
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     bool isValid(string s) {
 *         stack<char> st;
 *         
 *         for (char c : s) {
 *             if (c == '(' || c == '[' || c == '{') {
 *                 // 左括号入栈
 *                 st.push(c);
 *             } else {
 *                 // 右括号：检查匹配
 *                 if (st.empty()) return false;
 *                 
 *                 char top = st.top();
 *                 if ((c == ')' && top != '(') ||
 *                     (c == ']' && top != '[') ||
 *                     (c == '}' && top != '{')) {
 *                     return false;
 *                 }
 *                 
 *                 st.pop();
 *             }
 *         }
 *         
 *         // 所有括号都应该匹配完，栈应该为空
 *         return st.empty();
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n) - n 是字符串长度
 * 空间复杂度：O(n) - 最坏情况下栈中存储所有左括号
 */
