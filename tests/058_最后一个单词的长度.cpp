/*
 * 题目编号: 58
 * 题目名称: 最后一个单词的长度
 * 难度: 简单
 *
 * 题目描述:
 * 给你一个字符串 s，由若干单词组成，单词前后可能有空格。
 * 返回字符串中最后一个单词的长度。
 *
 * 单词：仅由字母组成、不包含空格的最大子串。
 *
 * 示例 1:
 * 输入: s = "Hello World"
 * 输出: 5
 *
 * 示例 2:
 * 输入: s = "   fly me   to   the moon  "
 * 输出: 4
 *
 * 示例 3:
 * 输入: s = "luffy is still joyboy"
 * 输出: 6
 */

/*
@Solution
class Solution {
public:
    int lengthOfLastWord(string s);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [58. 最后一个单词的长度]..." << endl;
    cout << string(50, '-') << endl;

    RUN_TEST(solution.lengthOfLastWord("Hello World"), 5, "测试用例 1: Hello World");
    RUN_TEST(solution.lengthOfLastWord("   fly me   to   the moon  "), 4, "测试用例 2: 多空格");
    RUN_TEST(solution.lengthOfLastWord("luffy is still joyboy"), 6, "测试用例 3: luffy is still joyboy");
    RUN_TEST(solution.lengthOfLastWord("a"), 1, "测试用例 4: a");
    RUN_TEST(solution.lengthOfLastWord("a "), 1, "测试用例 5: a(尾随空格)");
    RUN_TEST(solution.lengthOfLastWord("   "), 0, "测试用例 6: 全是空格（兼容性测试）");

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】从后往前扫 + 跳过空格
 * 最后一个单词一定在字符串尾部（可能有空格），所以：
 * 1) 从末尾开始跳过所有空格
 * 2) 再继续向前统计 avoid 空格的字符数量，直到遇到空格或到头
 *
 * 【常用点】
 * - while + 下标边界
 * - isspace / 直接判断 ' '
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     int lengthOfLastWord(string s) {
 *         int i = (int)s.size() - 1;
 *         while (i >= 0 && s[i] == ' ') i--;
 *         int len = 0;
 *         while (i >= 0 && s[i] != ' ') {
 *             len++;
 *             i--;
 *         }
 *         return len;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n)
 * - 空间：O(1)
 */

