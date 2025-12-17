/*
 * 题目编号: 125
 * 题目名称: 验证回文串
 * 难度: 简单
 * 
 * 题目描述:
 * 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。
 * 则可以认为该短语是一个回文串。
 * 
 * 字母和数字都属于字母数字字符。
 * 给你一个字符串 s，如果它是回文串，返回 true；否则，返回 false。
 * 
 * 示例 1:
 * 输入: s = "A man, a plan, a canal: Panama"
 * 输出: true
 * 解释: "amanaplanacanalpanama" 是回文串
 * 
 * 示例 2:
 * 输入: s = "race a car"
 * 输出: false
 * 解释: "raceacar" 不是回文串
 * 
 * 示例 3:
 * 输入: s = " "
 * 输出: true
 * 解释: 在移除非字母数字字符之后，s 是一个空字符串 ""。
 * 由于空字符串正着反着读都一样，所以是回文串。
 * 
 * 提示:
 * - 1 <= s.length <= 2 * 10^5
 * - s 仅由可打印的 ASCII 字符组成
 */

/*
@Solution
class Solution {
public:
    bool isPalindrome(string s);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [125. 验证回文串]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    RUN_TEST(solution.isPalindrome("A man, a plan, a canal: Panama"), true, 
             "测试用例 1: A man, a plan, a canal: Panama");
    
    // 测试用例 2
    RUN_TEST(solution.isPalindrome("race a car"), false, 
             "测试用例 2: race a car");
    
    // 测试用例 3
    RUN_TEST(solution.isPalindrome(" "), true, "测试用例 3: 空格");
    
    // 测试用例 4
    RUN_TEST(solution.isPalindrome("0P"), false, "测试用例 4: 0P");
    
    // 测试用例 5
    RUN_TEST(solution.isPalindrome("ab_a"), true, "测试用例 5: ab_a");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 验证回文串，需要忽略大小写和非字母数字字符。使用双指针从两端向中间比较。
 * 
 * 核心思路：
 * 1. 使用左右两个指针，分别从字符串两端开始
 * 2. 跳过非字母数字字符
 * 3. 比较字符（忽略大小写）
 * 
 * 【算法步骤】
 * 1. 初始化 left = 0, right = s.length() - 1
 * 2. 当 left < right 时：
 *    - 如果 s[left] 不是字母数字，left++
 *    - 如果 s[right] 不是字母数字，right--
 *    - 否则比较两个字符（转换为小写）
 *      * 如果不相等，返回 false
 *      * 如果相等，left++, right--
 * 3. 如果遍历完成，返回 true
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     bool isPalindrome(string s) {
 *         int left = 0;
 *         int right = s.length() - 1;
 *         
 *         while (left < right) {
 *             // 跳过非字母数字字符
 *             while (left < right && !isalnum(s[left])) {
 *                 left++;
 *             }
 *             while (left < right && !isalnum(s[right])) {
 *                 right--;
 *             }
 *             
 *             // 比较字符（忽略大小写）
 *             if (tolower(s[left]) != tolower(s[right])) {
 *                 return false;
 *             }
 *             
 *             left++;
 *             right--;
 *         }
 *         
 *         return true;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n) - n 是字符串长度
 * 空间复杂度：O(1) - 只使用常量空间
 */