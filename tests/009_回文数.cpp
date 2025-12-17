/*
 * 题目编号: 9
 * 题目名称: 回文数
 * 难度: 简单
 * 
 * 题目描述:
 * 给你一个整数 x，如果 x 是一个回文整数，返回 true；否则，返回 false。
 * 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 例如，121 是回文，而 123 不是。
 * 
 * 示例 1:
 * 输入: x = 121
 * 输出: true
 * 
 * 示例 2:
 * 输入: x = -121
 * 输出: false
 * 解释: 从左向右读, 为 -121。从右向左读, 为 121-。因此它不是一个回文数。
 * 
 * 示例 3:
 * 输入: x = 10
 * 输出: false
 * 解释: 从右向左读, 为 01。因此它不是一个回文数。
 * 
 * 提示:
 * - -2^31 <= x <= 2^31 - 1
 * 
 * 进阶：你能不将整数转为字符串来解决这个问题吗？
 */

/*
@Solution
class Solution {
public:
    bool isPalindrome(int x);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [9. 回文数]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    RUN_TEST(solution.isPalindrome(121), true, "测试用例 1: x=121");
    
    // 测试用例 2
    RUN_TEST(solution.isPalindrome(-121), false, "测试用例 2: x=-121");
    
    // 测试用例 3
    RUN_TEST(solution.isPalindrome(10), false, "测试用例 3: x=10");
    
    // 测试用例 4
    RUN_TEST(solution.isPalindrome(0), true, "测试用例 4: x=0");
    
    // 测试用例 5
    RUN_TEST(solution.isPalindrome(1221), true, "测试用例 5: x=1221");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 判断一个整数是否是回文数。可以将数字转换为字符串比较，但题目进阶要求不转换为字符串。
 * 更优的方法是反转数字的后半部分，然后与前半部分比较。
 * 
 * 核心思路：
 * 1. 负数一定不是回文数（前面有负号）
 * 2. 末尾为0的数字（除了0本身）不是回文数（如 10、100）
 * 3. 反转数字的后半部分，与前半部分比较
 * 
 * 【算法步骤】
 * 1. 特殊情况处理：负数和末尾为0的数返回 false
 * 2. 反转后半部分数字：
 *    - 循环条件：x > revertedNumber（后半部分还没反转完）
 *    - 每次取出 x 的最后一位加到 revertedNumber 中
 * 3. 比较：
 *    - 偶数位：x == revertedNumber
 *    - 奇数位：x == revertedNumber / 10（中间的数字可以忽略）
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     bool isPalindrome(int x) {
 *         // 负数或末尾为0的数（0除外）不是回文数
 *         if (x < 0 || (x % 10 == 0 && x != 0)) {
 *             return false;
 *         }
 *         
 *         int revertedNumber = 0;
 *         // 反转后半部分数字
 *         while (x > revertedNumber) {
 *             revertedNumber = revertedNumber * 10 + x % 10;
 *             x /= 10;
 *         }
 *         
 *         // 偶数位：x == revertedNumber
 *         // 奇数位：x == revertedNumber / 10（中间的数字可以忽略）
 *         return x == revertedNumber || x == revertedNumber / 10;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(log n) - n 是数字的位数
 * 空间复杂度：O(1)
 */
