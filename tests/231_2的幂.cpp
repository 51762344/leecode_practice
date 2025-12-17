/*
 * 题目编号: 231
 * 题目名称: 2 的幂
 * 难度: 简单
 *
 * 题目描述:
 * 给你一个整数 n，请你判断该整数是否是 2 的幂。
 * 如果是，返回 true；否则，返回 false。
 *
 * 示例 1:
 * 输入: n = 1
 * 输出: true
 *
 * 示例 2:
 * 输入: n = 16
 * 输出: true
 *
 * 示例 3:
 * 输入: n = 3
 * 输出: false
 */

/*
@Solution
class Solution {
public:
    bool isPowerOfTwo(int n);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [231. 2 的幂]..." << endl;
    cout << string(50, '-') << endl;

    RUN_TEST(solution.isPowerOfTwo(1), true, "测试用例 1: 1");
    RUN_TEST(solution.isPowerOfTwo(2), true, "测试用例 2: 2");
    RUN_TEST(solution.isPowerOfTwo(3), false, "测试用例 3: 3");
    RUN_TEST(solution.isPowerOfTwo(4), true, "测试用例 4: 4");
    RUN_TEST(solution.isPowerOfTwo(16), true, "测试用例 5: 16");
    RUN_TEST(solution.isPowerOfTwo(0), false, "测试用例 6: 0");
    RUN_TEST(solution.isPowerOfTwo(-2), false, "测试用例 7: -2");
    RUN_TEST(solution.isPowerOfTwo(1073741824), true, "测试用例 8: 2^30");
    RUN_TEST(solution.isPowerOfTwo(2147483647), false, "测试用例 9: INT_MAX");

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】n & (n - 1) 技巧
 * 2 的幂的二进制只有一个 1，例如：
 * 1: 0001
 * 2: 0010
 * 4: 0100
 * 8: 1000
 * 对于 n > 0，若 n 是 2 的幂，则 n & (n - 1) == 0。
 *
 * 【常用点】
 * - 位运算技巧：n & (n-1) 用来清除最低位的 1
 * - 先判断 n > 0
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     bool isPowerOfTwo(int n) {
 *         return n > 0 && ( (n & (n - 1)) == 0 );
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(1)
 * - 空间：O(1)
 */

