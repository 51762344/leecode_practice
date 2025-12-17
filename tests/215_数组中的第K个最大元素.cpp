/*
 * 题目编号: 215
 * 题目名称: 数组中的第K个最大元素
 * 难度: 中等
 *
 * 题目描述:
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 */

/*
@Solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

int main() {
    Solution solution;

    cout << "开始测试 [215. 数组中的第K个最大元素]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<int> nums = {3, 2, 1, 5, 6, 4};
        RUN_TEST(solution.findKthLargest(nums, 2), 5, "测试用例 1: [3,2,1,5,6,4], k=2");
    }

    {
        vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        RUN_TEST(solution.findKthLargest(nums, 4), 4, "测试用例 2: [3,2,3,1,2,4,5,5,6], k=4");
    }

    {
        vector<int> nums = {1};
        RUN_TEST(solution.findKthLargest(nums, 1), 1, "测试用例 3: [1], k=1");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】选择算法
 * 这题本质是找“第 k 大”，等价于找排序后下标 n-k 的元素。
 * 常用做法：
 * - 快速选择（Quickselect），平均 O(n)
 * - STL 的 nth_element（底层就是选择算法），平均 O(n)
 * - 小根堆维护 k 个元素，O(n log k)
 *
 * 【参考解法】（nth_element）
 * class Solution {
 * public:
 *     int findKthLargest(vector<int>& nums, int k) {
 *         int n = (int)nums.size();
 *         nth_element(nums.begin(), nums.begin() + (n - k), nums.end());
 *         return nums[n - k];
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：平均 O(n)
 * - 空间：O(1)（就地重排）
 */
