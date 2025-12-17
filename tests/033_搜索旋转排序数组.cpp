/*
 * 题目编号: 33
 * 题目名称: 搜索旋转排序数组
 * 难度: 中等
 *
 * 题目描述:
 * 整数数组 nums 按升序排列，数组中的值 互不相同。
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了旋转，
 * 使得数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]。
 * 给你旋转后的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1。
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 */

/*
@Solution
class Solution {
public:
    int search(vector<int>& nums, int target);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

int main() {
    Solution solution;

    cout << "开始测试 [33. 搜索旋转排序数组]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        RUN_TEST(solution.search(nums, 0), 4, "测试用例 1: target=0");
        RUN_TEST(solution.search(nums, 3), -1, "测试用例 2: target=3");
    }

    {
        vector<int> nums = {1};
        RUN_TEST(solution.search(nums, 0), -1, "测试用例 3: [1], target=0");
        RUN_TEST(solution.search(nums, 1), 0, "测试用例 4: [1], target=1");
    }

    {
        vector<int> nums = {6, 7, 8, 1, 2, 3, 4, 5};
        RUN_TEST(solution.search(nums, 6), 0, "测试用例 5: target=6");
        RUN_TEST(solution.search(nums, 5), 7, "测试用例 6: target=5");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】二分查找（每次确定哪一半有序）
 * 旋转数组仍然满足：任意时刻 [l..mid] 或 [mid..r] 至少一半是单调有序的。
 * - 若 nums[l] <= nums[mid]，说明左半段有序；
 *   - 若 target 落在 [nums[l], nums[mid])，去左边；否则去右边。
 * - 否则右半段有序；
 *   - 若 target 落在 (nums[mid], nums[r]]，去右边；否则去左边。
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     int search(vector<int>& nums, int target) {
 *         int l = 0, r = (int)nums.size() - 1;
 *         while (l <= r) {
 *             int mid = l + (r - l) / 2;
 *             if (nums[mid] == target) return mid;
 *             if (nums[l] <= nums[mid]) { // 左半有序
 *                 if (nums[l] <= target && target < nums[mid]) r = mid - 1;
 *                 else l = mid + 1;
 *             } else { // 右半有序
 *                 if (nums[mid] < target && target <= nums[r]) l = mid + 1;
 *                 else r = mid - 1;
 *             }
 *         }
 *         return -1;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(log n)
 * - 空间：O(1)
 */
