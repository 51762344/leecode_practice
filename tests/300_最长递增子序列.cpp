/*
 * 题目编号: 300
 * 题目名称: 最长递增子序列
 * 难度: 中等
 *
 * 题目描述:
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
 */

/*
@Solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

int main() {
    Solution solution;

    cout << "开始测试 [300. 最长递增子序列]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
        RUN_TEST(solution.lengthOfLIS(nums), 4, "测试用例 1: [10,9,2,5,3,7,101,18]");
    }

    {
        vector<int> nums = {0, 1, 0, 3, 2, 3};
        RUN_TEST(solution.lengthOfLIS(nums), 4, "测试用例 2: [0,1,0,3,2,3]");
    }

    {
        vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
        RUN_TEST(solution.lengthOfLIS(nums), 1, "测试用例 3: 全相等");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】贪心 + 二分（“扑克牌/ patience sorting”）
 * 用数组 tails：tails[len-1] 表示“长度为 len 的递增子序列，其末尾元素的最小可能值”。
 * 遍历每个 x：
 * - 在 tails 中找到第一个 >= x 的位置，用 x 替换（让末尾尽量小，便于后续接更大的数）
 * - 若找不到（x 最大），直接 push_back，长度 +1
 * 最终 tails.size() 就是 LIS 长度。
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     int lengthOfLIS(vector<int>& nums) {
 *         vector<int> tails;
 *         for (int x : nums) {
 *             auto it = lower_bound(tails.begin(), tails.end(), x);
 *             if (it == tails.end()) tails.push_back(x);
 *             else *it = x;
 *         }
 *         return (int)tails.size();
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n log n)
 * - 空间：O(n)
 */
