/*
 * 题目编号: 35
 * 题目名称: 搜索插入位置
 * 难度: 简单
 *
 * 题目描述:
 * 给定一个排序数组 nums 和一个目标值 target，在 nums 中找到 target，并返回其索引。
 * 如果不存在，则返回它将会被按顺序插入的位置。
 *
 * 要求：时间复杂度 O(log n)
 *
 * 示例 1:
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 *
 * 示例 2:
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 */

/*
@Solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [35. 搜索插入位置]..." << endl;
    cout << string(50, '-') << endl;

    vector<int> nums1 = {1, 3, 5, 6};
    RUN_TEST(solution.searchInsert(nums1, 5), 2, "测试用例 1: [1,3,5,6], target=5");
    RUN_TEST(solution.searchInsert(nums1, 2), 1, "测试用例 2: [1,3,5,6], target=2");
    RUN_TEST(solution.searchInsert(nums1, 7), 4, "测试用例 3: [1,3,5,6], target=7");
    RUN_TEST(solution.searchInsert(nums1, 0), 0, "测试用例 4: [1,3,5,6], target=0");

    vector<int> nums2 = {1};
    RUN_TEST(solution.searchInsert(nums2, 1), 0, "测试用例 5: [1], target=1");
    RUN_TEST(solution.searchInsert(nums2, 0), 0, "测试用例 6: [1], target=0");
    RUN_TEST(solution.searchInsert(nums2, 2), 1, "测试用例 7: [1], target=2");

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】二分 / lower_bound
 * 因为 nums 已经升序，要求 O(log n)，所以用二分查找。
 * 目标是返回“第一个 >= target 的位置”，这正是 lower_bound 的语义：
 * - 若 target 存在，lower_bound 指向它的下标
 * - 若不存在，lower_bound 指向应该插入的位置
 *
 * 【推荐写法】
 * 1) STL：lower_bound(nums.begin(), nums.end(), target) - nums.begin()
 * 2) 手写二分：维护 [l, r)（左闭右开），最终 l 即插入位置
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     int searchInsert(vector<int>& nums, int target) {
 *         return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(log n)
 * - 空间：O(1)
 */

