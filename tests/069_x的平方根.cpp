/*
 * 题目编号: 69
 * 题目名称: x 的平方根
 * 难度: 简单
 *
 * 题目描述:
 * 给你一个非负整数 x ，计算并返回 x 的算术平方根。
 * 由于返回类型是整数，结果只保留整数部分（向下取整）。
 *
 * 示例 1:
 * 输入: x = 4
 * 输出: 2
 *
 * 示例 2:
 * 输入: x = 8
 * 输出: 2
 */

/*
@Solution
class Solution {
public:
    int mySqrt(int x);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [69. x 的平方根]..." << endl;
    cout << string(50, '-') << endl;

    RUN_TEST(solution.mySqrt(0), 0, "测试用例 1: x=0");
    RUN_TEST(solution.mySqrt(1), 1, "测试用例 2: x=1");
    RUN_TEST(solution.mySqrt(4), 2, "测试用例 3: x=4");
    RUN_TEST(solution.mySqrt(8), 2, "测试用例 4: x=8");
    RUN_TEST(solution.mySqrt(9), 3, "测试用例 5: x=9");
    RUN_TEST(solution.mySqrt(15), 3, "测试用例 6: x=15");
    RUN_TEST(solution.mySqrt(2147395599), 46339, "测试用例 7: 大数边界(46339^2 < x < 46340^2)");
    RUN_TEST(solution.mySqrt(2147483647), 46340, "测试用例 8: INT_MAX");

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】二分答案（整数开方）
 * 设答案为 r，满足 r^2 <= x < (r+1)^2。
 * 在区间 [0, x] 上二分查找最大的 r，使 r^2 <= x。
 *
 * 【注意点：避免溢出】
 * 判断 mid*mid <= x 时，用 long long：
 * (long long)mid * mid <= x
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     int mySqrt(int x) {
 *         long long l = 0, r = x; // 答案在 [0, x]
 *         while (l <= r) {
 *             long long mid = (l + r) >> 1;
 *             long long sq = mid * mid;
 *             if (sq <= x) {
 *                 l = mid + 1;
 *             } else {
 *                 r = mid - 1;
 *             }
 *         }
 *         return (int)r;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(log x)
 * - 空间：O(1)
 */

