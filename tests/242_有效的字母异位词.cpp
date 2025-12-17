/*
 * 题目编号: 242
 * 题目名称: 有效的字母异位词
 * 难度: 简单
 * 
 * 题目描述:
 * 给定两个字符串 s 和 t，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意: 若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 示例 1:
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 示例 2:
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 提示:
 * - 1 <= s.length, t.length <= 5 * 10^4
 * - s 和 t 仅包含小写字母
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 */

/*
@Solution
class Solution {
public:
    bool isAnagram(string s, string t);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [242. 有效的字母异位词]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    RUN_TEST(solution.isAnagram("anagram", "nagaram"), true, 
             "测试用例 1: s=\"anagram\", t=\"nagaram\"");
    
    // 测试用例 2
    RUN_TEST(solution.isAnagram("rat", "car"), false, 
             "测试用例 2: s=\"rat\", t=\"car\"");
    
    // 测试用例 3: 长度不同
    RUN_TEST(solution.isAnagram("a", "ab"), false, 
             "测试用例 3: s=\"a\", t=\"ab\" (长度不同)");
    
    // 测试用例 4: 相同字符串
    RUN_TEST(solution.isAnagram("abc", "abc"), true, 
             "测试用例 4: s=\"abc\", t=\"abc\"");
    
    // 测试用例 5: 字符频率不同
    RUN_TEST(solution.isAnagram("aacc", "ccac"), false, 
             "测试用例 5: s=\"aacc\", t=\"ccac\"");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 字母异位词的特点是两个字符串包含相同的字符，只是顺序不同。
 * 判断方法有多种，从排序到哈希表。
 * 
 * 核心思路：
 * 1. 如果两个字符串长度不同，直接返回 false
 * 2. 统计每个字符出现的次数
 * 3. 比较两个字符串的字符频率是否相同
 * 
 * 【算法步骤】
 * 方法1（哈希表）：
 * 1. 检查长度，不同则返回 false
 * 2. 创建哈希表统计字符频率
 * 3. 遍历 s，增加字符计数
 * 4. 遍历 t，减少字符计数
 * 5. 检查所有计数是否为 0
 * 
 * 【参考解法】
 * 
 * // 方法1：哈希表（数组）
 * class Solution {
 * public:
 *     bool isAnagram(string s, string t) {
 *         // 长度不同，直接返回 false
 *         if (s.length() != t.length()) {
 *             return false;
 *         }
 *         
 *         // 因为只包含小写字母，用数组模拟哈希表
 *         int count[26] = {0};
 *         
 *         // 统计字符频率
 *         for (int i = 0; i < s.length(); i++) {
 *             count[s[i] - 'a']++;
 *             count[t[i] - 'a']--;
 *         }
 *         
 *         // 检查所有字符的计数是否为 0
 *         for (int i = 0; i < 26; i++) {
 *             if (count[i] != 0) {
 *                 return false;
 *             }
 *         }
 *         
 *         return true;
 *     }
 * };
 * 
 * // 方法2：排序
 * class Solution {
 * public:
 *     bool isAnagram(string s, string t) {
 *         if (s.length() != t.length()) {
 *             return false;
 *         }
 *         
 *         // 排序后比较
 *         sort(s.begin(), s.end());
 *         sort(t.begin(), t.end());
 *         
 *         return s == t;
 *     }
 * };
 * 
 * // 方法3：unordered_map（适合 unicode 字符）
 * class Solution {
 * public:
 *     bool isAnagram(string s, string t) {
 *         if (s.length() != t.length()) {
 *             return false;
 *         }
 *         
 *         unordered_map<char, int> count;
 *         
 *         // 统计 s 中字符频率
 *         for (char c : s) {
 *             count[c]++;
 *         }
 *         
 *         // 减去 t 中字符频率
 *         for (char c : t) {
 *             count[c]--;
 *             if (count[c] < 0) {
 *                 return false;
 *             }
 *         }
 *         
 *         return true;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（哈希表/数组）：
 * - 时间复杂度：O(n) - n 为字符串长度
 * - 空间复杂度：O(1) - 数组大小固定为 26
 * 
 * 方法2（排序）：
 * - 时间复杂度：O(n log n) - 排序的时间
 * - 空间复杂度：O(log n) 或 O(n) - 取决于排序算法
 * 
 * 方法3（unordered_map）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(k) - k 为字符种类数
 * 
 * 【知识点】
 * - 哈希表的应用
 * - 字符频率统计
 * - 排序的应用
 * - 数组优化（小写字母用数组代替哈希表）
 */
