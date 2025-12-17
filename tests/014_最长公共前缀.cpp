/*
 * 题目编号: 14
 * 题目名称: 最长公共前缀
 * 难度: 简单
 * 
 * 题目描述:
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 输入: strs = ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 示例 2:
 * 输入: strs = ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀
 * 
 * 提示:
 * - 1 <= strs.length <= 200
 * - 0 <= strs[i].length <= 200
 * - strs[i] 仅由小写英文字母组成
 */

/*
@Solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [14. 最长公共前缀]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    RUN_TEST(solution.longestCommonPrefix(strs1), string("fl"), 
             "测试用例 1: [flower,flow,flight]");
    
    // 测试用例 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    RUN_TEST(solution.longestCommonPrefix(strs2), string(""), 
             "测试用例 2: [dog,racecar,car]");
    
    // 测试用例 3
    vector<string> strs3 = {"ab", "a"};
    RUN_TEST(solution.longestCommonPrefix(strs3), string("a"), 
             "测试用例 3: [ab,a]");
    
    // 测试用例 4
    vector<string> strs4 = {"abc", "abc", "abc"};
    RUN_TEST(solution.longestCommonPrefix(strs4), string("abc"), 
             "测试用例 4: [abc,abc,abc]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 找到字符串数组中的最长公共前缀。可以采用多种方法：
 * 1. 横向扫描：依次比较字符串，逐步缩短公共前缀
 * 2. 纵向扫描：按字符位置逐个比较所有字符串的同一位置字符
 * 
 * 核心思路（纵向扫描）：
 * 以第一个字符串为基准，逐个字符比较所有字符串的对应位置。
 * 
 * 【算法步骤】
 * 1. 如果数组为空，返回空字符串
 * 2. 遍历第一个字符串的每个字符位置 i：
 *    - 取出第一个字符串的第 i 个字符
 *    - 检查其他所有字符串的第 i 个字符是否相同
 *    - 如果不同或某个字符串长度不够，返回 [0, i) 的子串
 * 3. 如果遍历完成，说明第一个字符串就是公共前缀
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     string longestCommonPrefix(vector<string>& strs) {
 *         if (strs.empty()) return "";
 *         
 *         // 以第一个字符串为基准
 *         string prefix = strs[0];
 *         
 *         for (int i = 0; i < prefix.length(); i++) {
 *             char c = prefix[i];
 *             
 *             // 检查其他字符串的第 i 个字符
 *             for (int j = 1; j < strs.size(); j++) {
 *                 // 如果某个字符串长度不够或字符不匹配
 *                 if (i >= strs[j].length() || strs[j][i] != c) {
 *                     return prefix.substr(0, i);
 *                 }
 *             }
 *         }
 *         
 *         return prefix;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(S) - S 是所有字符串的字符总数
 * 空间复杂度：O(1)
 */