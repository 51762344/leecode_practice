/*
 * 题目编号: 67
 * 题目名称: 二进制求和
 * 难度: 简单
 *
 * 题目描述:
 * 给你两个二进制字符串 a 和 b，以二进制字符串的形式返回它们的和。
 *
 * 示例 1:
 * 输入: a = "11", b = "1"
 * 输出: "100"
 *
 * 示例 2:
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 */

/*
@Solution
class Solution {
public:
    string addBinary(string a, string b);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [67. 二进制求和]..." << endl;
    cout << string(50, '-') << endl;

    RUN_TEST(solution.addBinary("11", "1"), string("100"), "测试用例 1: 11 + 1");
    RUN_TEST(solution.addBinary("1010", "1011"), string("10101"), "测试用例 2: 1010 + 1011");
    RUN_TEST(solution.addBinary("0", "0"), string("0"), "测试用例 3: 0 + 0");
    RUN_TEST(solution.addBinary("0", "1"), string("1"), "测试用例 4: 0 + 1");
    RUN_TEST(solution.addBinary("1", "1"), string("10"), "测试用例 5: 1 + 1");
    RUN_TEST(solution.addBinary("1111", "1111"), string("11110"), "测试用例 6: 1111 + 1111");

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】模拟加法（从低位到高位）+ 进位 carry
 * 两个字符串从末尾开始逐位相加：
 * sum = bitA + bitB + carry
 * 当前位 = sum % 2，新的进位 = sum / 2
 *
 * 【常用点】
 * - 字符转数字：a[i] - '0'
 * - 结果反转：reverse(res.begin(), res.end())
 * - 也可以用 string.push_back / string +=
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     string addBinary(string a, string b) {
 *         int i = (int)a.size() - 1;
 *         int j = (int)b.size() - 1;
 *         int carry = 0;
 *         string res;
 *         while (i >= 0 || j >= 0 || carry) {
 *             int sum = carry;
 *             if (i >= 0) sum += a[i--] - '0';
 *             if (j >= 0) sum += b[j--] - '0';
 *             res.push_back(char('0' + (sum & 1)));
 *             carry = sum >> 1;
 *         }
 *         reverse(res.begin(), res.end());
 *         return res;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n)
 * - 空间：O(n)
 */

