/*
 * 题目编号: 003
 * 题目名称: 无重复字符的最长子串
 * 难度: 中等
 * 
 * 题目描述:
 * 给定一个字符串 s，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 示例 2:
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 示例 3:
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 提示:
 * - 0 <= s.length <= 5 * 10^4
 * - s 由英文字母、数字、符号和空格组成
 */

/*
@Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s);
};
@EndSolution
*/

#include "../leetcode_framework.h"

#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [003. 无重复字符的最长子串]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    RUN_TEST(solution.lengthOfLongestSubstring("abcabcbb"), 3, "测试用例 1: abcabcbb");
    
    // 测试用例 2
    RUN_TEST(solution.lengthOfLongestSubstring("bbbbb"), 1, "测试用例 2: bbbbb");
    
    // 测试用例 3
    RUN_TEST(solution.lengthOfLongestSubstring("pwwkew"), 3, "测试用例 3: pwwkew");
    
    // 测试用例 4: 空字符串
    RUN_TEST(solution.lengthOfLongestSubstring(""), 0, "测试用例 4: 空字符串");
    
    // 测试用例 5: 单字符
    RUN_TEST(solution.lengthOfLongestSubstring("a"), 1, "测试用例 5: 单字符");
    
    // 测试用例 6: 全部不重复
    RUN_TEST(solution.lengthOfLongestSubstring("abcdef"), 6, "测试用例 6: 全部不重复");
    
    // 测试用例 7: 有空格和符号
    RUN_TEST(solution.lengthOfLongestSubstring("a b c a"), 3, "测试用例 7: 有空格和符号");
    
    // 测试用例 8: 复杂情况
    RUN_TEST(solution.lengthOfLongestSubstring("dvdf"), 3, "测试用例 8: dvdf");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的**滑动窗口**问题，也是面试超高频题（字节跳动、腾讯必考）。
 * 
 * 核心思路：
 * 使用**滑动窗口 + 哈希表**的方式维护一个无重复字符的窗口。
 * 
 * 【算法步骤】
 * 1. 使用两个指针 left 和 right 表示窗口的左右边界
 * 2. 使用哈希表（unordered_map 或 数组）记录字符最后出现的位置
 * 3. right 指针不断向右移动扩大窗口：
 *    - 如果当前字符已在窗口中，移动 left 到重复字符的下一个位置
 *    - 更新当前字符的位置
 *    - 更新最大长度
 * 4. 返回最大长度
 * 
 * 【参考解法】
 * 
 * // 方法1：滑动窗口 + 哈希表（推荐）
 * class Solution {
 * public:
 *     int lengthOfLongestSubstring(string s) {
 *         unordered_map<char, int> window;  // 记录字符最后出现的位置
 *         int left = 0, maxLen = 0;
 *         
 *         for (int right = 0; right < s.length(); right++) {
 *             char c = s[right];
 *             
 *             // 如果字符已在窗口中，移动左指针
 *             if (window.count(c) && window[c] >= left) {
 *                 left = window[c] + 1;
 *             }
 *             
 *             // 更新字符位置
 *             window[c] = right;
 *             
 *             // 更新最大长度
 *             maxLen = max(maxLen, right - left + 1);
 *         }
 *         
 *         return maxLen;
 *     }
 * };
 * 
 * // 方法2：滑动窗口 + 数组优化（更快）
 * class Solution {
 * public:
 *     int lengthOfLongestSubstring(string s) {
 *         vector<int> charIndex(128, -1);  // ASCII 字符
 *         int left = 0, maxLen = 0;
 *         
 *         for (int right = 0; right < s.length(); right++) {
 *             // 如果字符已出现在当前窗口中
 *             if (charIndex[s[right]] >= left) {
 *                 left = charIndex[s[right]] + 1;
 *             }
 *             
 *             charIndex[s[right]] = right;
 *             maxLen = max(maxLen, right - left + 1);
 *         }
 *         
 *         return maxLen;
 *     }
 * };
 * 
 * // 方法3：滑动窗口模板写法（更易理解）
 * class Solution {
 * public:
 *     int lengthOfLongestSubstring(string s) {
 *         unordered_map<char, int> window;
 *         int left = 0, right = 0;
 *         int maxLen = 0;
 *         
 *         while (right < s.length()) {
 *             // 扩大窗口
 *             char c = s[right];
 *             right++;
 *             window[c]++;
 *             
 *             // 如果有重复，收缩窗口
 *             while (window[c] > 1) {
 *                 char d = s[left];
 *                 left++;
 *                 window[d]--;
 *             }
 *             
 *             // 更新结果
 *             maxLen = max(maxLen, right - left);
 *         }
 *         
 *         return maxLen;
 *     }
 * };
 * 
 * 【复杂度分析】
 * - 时间复杂度：O(n) - 每个字符最多被访问两次（right 和 left 各一次）
 * - 空间复杂度：O(min(n, m)) - m 是字符集大小（ASCII 为 128）
 * 
 * 【关键点】
 * 1. 滑动窗口的核心：维护一个满足条件的窗口
 * 2. 当窗口不满足条件时，收缩左边界
 * 3. 使用哈希表快速判断字符是否在窗口中
 * 4. 注意边界条件：空字符串、单字符
 * 
 * 【滑动窗口模板】
 * 这道题是学习滑动窗口的最佳入门题，掌握这道题的思路后，
 * 可以解决 LeetCode 76, 438, 567 等一系列滑动窗口问题。
 * 
 * 滑动窗口通用模板：
 * ```
 * left = 0, right = 0
 * while (right < s.length()):
 *     扩大窗口（right++）
 *     更新窗口数据
 *     
 *     while (窗口需要收缩):
 *         收缩窗口（left++）
 *         更新窗口数据
 *     
 *     更新答案
 * ```
 * 
 * 【面试高频程度】⭐⭐⭐⭐⭐
 * - 字节跳动：超高频
 * - 腾讯：高频
 * - 阿里：高频
 * - 美团：高频
 */

