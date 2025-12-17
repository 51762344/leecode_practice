/*
 * 题目编号: 190
 * 题目名称: 颠倒二进制位
 * 难度: 简单
 *
 * 题目描述:
 * 颠倒给定的 32 位无符号整数的二进制位。
 *
 * 示例 1:
 * 输入: n = 00000010100101000001111010011100
 * 输出:     00111001011110000010100101000000
 *
 * 示例 2:
 * 输入: n = 11111111111111111111111111111101
 * 输出:     10111111111111111111111111111111
 */

/*
@Solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [190. 颠倒二进制位]..." << endl;
    cout << string(50, '-') << endl;

    // 43261596 -> 964176192 (LeetCode 官方样例)
    RUN_TEST(solution.reverseBits((uint32_t)43261596), (uint32_t)964176192, "测试用例 1: 43261596");

    // 4294967293 -> 3221225471 (LeetCode 官方样例)
    RUN_TEST(solution.reverseBits((uint32_t)4294967293u), (uint32_t)3221225471u, "测试用例 2: 4294967293");

    RUN_TEST(solution.reverseBits((uint32_t)0), (uint32_t)0, "测试用例 3: 0");
    RUN_TEST(solution.reverseBits((uint32_t)1), (uint32_t)2147483648u, "测试用例 4: 1");

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】逐位取出 + 拼回去
 * 每次取最低位 (n & 1)，把它放到结果的最低位，然后结果左移一位。
 *
 * res = (res << 1) | (n & 1)
 * n >>= 1
 * 重复 32 次。
 *
 * 【常用点】
 * - 位运算：&、|、<<、>>
 * - 无符号类型：uint32_t
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     uint32_t reverseBits(uint32_t n) {
 *         uint32_t res = 0;
 *         for (int i = 0; i < 32; i++) {
 *             res = (res << 1) | (n & 1u);
 *             n >>= 1;
 *         }
 *         return res;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(32) ~ O(1)
 * - 空间：O(1)
 */

