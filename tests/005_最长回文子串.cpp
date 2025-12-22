/*
 * 题目编号: 005
 * 题目名称: 最长回文子串
 * 难度: 中等
 * 
 * 题目描述:
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 示例 1：
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 示例 2：
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 提示：
 * - 1 <= s.length <= 1000
 * - s 仅由数字和英文字母组成
 */

/*
@Solution
class Solution {
public:
    string longestPalindrome(string s);
};
@EndSolution
*/

#include "../leetcode_framework.h"

#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [005. 最长回文子串]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    string result1 = solution.longestPalindrome("babad");
    bool test1 = (result1 == "bab" || result1 == "aba");
    if (test1) {
        cout << "✓ 测试通过: 测试用例 1: babad" << endl;
        test_framework.assert_equal(true, true, "");
    } else {
        cout << "✗ 测试失败: 测试用例 1: babad, 期望 bab 或 aba, 实际 " << result1 << endl;
        test_framework.assert_equal(true, false, "");
    }
    
    // 测试用例 2
    RUN_TEST(solution.longestPalindrome("cbbd"), string("bb"), "测试用例 2: cbbd");
    
    // 测试用例 3: 单字符
    RUN_TEST(solution.longestPalindrome("a"), string("a"), "测试用例 3: 单字符");
    
    // 测试用例 4: 两个字符
    RUN_TEST(solution.longestPalindrome("ac"), string("a"), "测试用例 4: ac");
    
    // 测试用例 5: 全部相同
    RUN_TEST(solution.longestPalindrome("aaaa"), string("aaaa"), "测试用例 5: aaaa");
    
    // 测试用例 6: 偶数长度回文
    RUN_TEST(solution.longestPalindrome("abba"), string("abba"), "测试用例 6: abba");
    
    // 测试用例 7: 奇数长度回文
    RUN_TEST(solution.longestPalindrome("racecar"), string("racecar"), "测试用例 7: racecar");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的**字符串**问题，面试高频（腾讯、美团、字节必考）。
 * 
 * 核心思想：
 * 回文串的特点是：从中心向两边扩散，左右对称。
 * 
 * 【算法步骤】
 * 
 * 方法1：中心扩散法（推荐，最易理解）
 * 1. 遍历每个可能的回文中心
 * 2. 从中心向两边扩散，检查是否对称
 * 3. 注意：回文中心可能是一个字符（奇数长度）或两个字符（偶数长度）
 * 4. 记录最长的回文子串
 * 
 * 方法2：动态规划
 * 1. dp[i][j] 表示 s[i..j] 是否为回文串
 * 2. 状态转移：dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]
 * 3. 边界条件：单字符和两个相同字符都是回文
 * 
 * 方法3：Manacher 算法（面试不要求）
 * 时间复杂度 O(n)，但实现复杂，面试中很少用到。
 * 
 * 【参考解法】
 * 
 * // 方法1：中心扩散法（推荐）
 * class Solution {
 * public:
 *     string longestPalindrome(string s) {
 *         if (s.empty()) return "";
 *         
 *         int start = 0, maxLen = 0;
 *         
 *         for (int i = 0; i < s.length(); i++) {
 *             // 奇数长度回文（中心是一个字符）
 *             int len1 = expandAroundCenter(s, i, i);
 *             // 偶数长度回文（中心是两个字符）
 *             int len2 = expandAroundCenter(s, i, i + 1);
 *             
 *             int len = max(len1, len2);
 *             
 *             // 更新最长回文子串
 *             if (len > maxLen) {
 *                 maxLen = len;
 *                 start = i - (len - 1) / 2;
 *             }
 *         }
 *         
 *         return s.substr(start, maxLen);
 *     }
 *     
 * private:
 *     // 从中心向两边扩散
 *     int expandAroundCenter(const string& s, int left, int right) {
 *         while (left >= 0 && right < s.length() && s[left] == s[right]) {
 *             left--;
 *             right++;
 *         }
 *         // 返回回文串长度
 *         return right - left - 1;
 *     }
 * };
 * 
 * // 方法2：动态规划
 * class Solution {
 * public:
 *     string longestPalindrome(string s) {
 *         int n = s.length();
 *         if (n < 2) return s;
 *         
 *         vector<vector<bool>> dp(n, vector<bool>(n, false));
 *         int start = 0, maxLen = 1;
 *         
 *         // 所有单字符都是回文
 *         for (int i = 0; i < n; i++) {
 *             dp[i][i] = true;
 *         }
 *         
 *         // 枚举子串长度
 *         for (int len = 2; len <= n; len++) {
 *             for (int i = 0; i < n; i++) {
 *                 int j = i + len - 1;
 *                 if (j >= n) break;
 *                 
 *                 if (s[i] != s[j]) {
 *                     dp[i][j] = false;
 *                 } else {
 *                     if (len <= 3) {
 *                         dp[i][j] = true;
 *                     } else {
 *                         dp[i][j] = dp[i+1][j-1];
 *                     }
 *                 }
 *                 
 *                 if (dp[i][j] && len > maxLen) {
 *                     maxLen = len;
 *                     start = i;
 *                 }
 *             }
 *         }
 *         
 *         return s.substr(start, maxLen);
 *     }
 * };
 * 
 * 【复杂度分析】
 * 
 * 方法1（中心扩散）：
 * - 时间复杂度：O(n²) - n 个中心，每个中心最多扩散 n 次
 * - 空间复杂度：O(1) - 只需常数额外空间 ⭐⭐⭐
 * 
 * 方法2（动态规划）：
 * - 时间复杂度：O(n²) - 两层循环
 * - 空间复杂度：O(n²) - 需要 dp 数组
 * 
 * 【关键点】
 * 
 * 1. **中心扩散的两种情况**：
 *    - 奇数长度回文：中心是一个字符，如 "aba"
 *    - 偶数长度回文：中心是两个字符，如 "abba"
 * 
 * 2. **为什么中心扩散更好**：
 *    - 代码简洁，易于理解
 *    - 空间复杂度 O(1)
 *    - 更符合直觉
 * 
 * 3. **计算起始位置**：
 *    - 当前中心位置是 i，回文长度是 len
 *    - 起始位置 start = i - (len - 1) / 2
 *    - 例如：i=3, len=5, start = 3 - 2 = 1
 * 
 * 4. **边界条件**：
 *    - 空字符串
 *    - 单字符
 *    - 两个字符
 * 
 * 【图解示例】
 * s = "babad"
 * 
 * i=0: 中心='b', 回文="b", 长度=1
 * i=1: 中心='a', 回文="bab", 长度=3 ⭐
 * i=2: 中心='b', 回文="aba", 长度=3 ⭐
 * i=3: 中心='a', 回文="aba", 长度=3
 * i=4: 中心='d', 回文="d", 长度=1
 * 
 * 最长回文："bab" 或 "aba"（都是长度 3）
 * 
 * 【面试高频程度】⭐⭐⭐⭐⭐
 * - 腾讯：超高频
 * - 美团：高频
 * - 字节跳动：高频
 * - 阿里：高频
 * 
 * 【相关题目】
 * - LeetCode 647: 回文子串（统计回文子串数量）
 * - LeetCode 516: 最长回文子序列（动态规划）
 * - LeetCode 214: 最短回文串（KMP + 回文）
 * 
 * 【面试技巧】
 * 1. 优先使用中心扩散法（代码简洁，空间O(1)）
 * 2. 如果面试官要求，可以补充DP解法
 * 3. 不要提Manacher算法（太复杂，面试不考）
 */

