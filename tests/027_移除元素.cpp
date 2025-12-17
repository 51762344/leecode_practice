/*
 * 题目编号: 27
 * 题目名称: 移除元素
 * 难度: 简单
 * 
 * 题目描述:
 * 给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素。
 * 元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
 * 
 * 假设 nums 中不等于 val 的元素数量为 k，你需要确保以下事情：
 * - 更改数组 nums，使 nums 的前 k 个元素包含不等于 val 的元素。
 * - nums 的其余元素与 nums 的大小不重要。
 * - 返回 k。
 * 
 * 示例 1:
 * 输入: nums = [3,2,2,3], val = 3
 * 输出: 2, nums = [2,2,_,_]
 * 解释: 你的函数函数应该返回 k = 2, 并且 nums 中的前两个元素均为 2。
 * 你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
 * 
 * 示例 2:
 * 输入: nums = [0,1,2,2,3,0,4,2], val = 2
 * 输出: 5, nums = [0,1,4,0,3,_,_,_]
 * 解释: 你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
 * 注意这五个元素可以任意顺序返回。
 * 你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
 * 
 * 提示:
 * - 0 <= nums.length <= 100
 * - 0 <= nums[i] <= 50
 * - 0 <= val <= 100
 */

/*
@Solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [27. 移除元素]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {3, 2, 2, 3};
    int k1 = solution.removeElement(nums1, 3);
    vector<int> result1(nums1.begin(), nums1.begin() + k1);
    sort(result1.begin(), result1.end());  // 排序后比较（因为顺序可以不同）
    RUN_TEST(result1, vector<int>({2, 2}), "测试用例 1: [3,2,2,3], val=3");
    
    // 测试用例 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = solution.removeElement(nums2, 2);
    vector<int> result2(nums2.begin(), nums2.begin() + k2);
    sort(result2.begin(), result2.end());
    RUN_TEST(result2, vector<int>({0, 0, 1, 3, 4}), 
             "测试用例 2: [0,1,2,2,3,0,4,2], val=2");
    
    // 测试用例 3
    vector<int> nums3 = {1};
    int k3 = solution.removeElement(nums3, 1);
    vector<int> result3(nums3.begin(), nums3.begin() + k3);
    RUN_TEST(result3, vector<int>({}), "测试用例 3: [1], val=1");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 原地移除数组中所有值等于 val 的元素，同样使用双指针技巧。
 * 
 * 核心思路：
 * 1. 慢指针指向下一个非 val 元素应该放置的位置
 * 2. 快指针遍历数组
 * 3. 当快指针指向的元素不等于 val 时，将其复制到慢指针位置
 * 
 * 【算法步骤】
 * 1. 初始化慢指针 slow = 0
 * 2. 快指针遍历整个数组：
 *    - 如果 nums[fast] != val
 *    - 将 nums[fast] 复制到 nums[slow]
 *    - slow++
 * 3. 返回 slow（新数组长度）
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int removeElement(vector<int>& nums, int val) {
 *         int slow = 0;
 *         
 *         for (int fast = 0; fast < nums.size(); fast++) {
 *             // 如果当前元素不等于 val，保留它
 *             if (nums[fast] != val) {
 *                 nums[slow] = nums[fast];
 *                 slow++;
 *             }
 *         }
 *         
 *         return slow;
 *     }
 * };
 * 
 * 【优化解法：双向指针】
 * 当要删除的元素很少时，可以从两端向中间移动，减少赋值次数。
 * 
 * class Solution {
 * public:
 *     int removeElement(vector<int>& nums, int val) {
 *         int left = 0;
 *         int right = nums.size() - 1;
 *         
 *         while (left <= right) {
 *             if (nums[left] == val) {
 *                 nums[left] = nums[right];
 *                 right--;
 *             } else {
 *                 left++;
 *             }
 *         }
 *         
 *         return left;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */