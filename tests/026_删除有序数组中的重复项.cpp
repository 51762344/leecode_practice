/*
 * 题目编号: 26
 * 题目名称: 删除有序数组中的重复项
 * 难度: 简单
 * 
 * 题目描述:
 * 给你一个非严格递增排列的数组 nums，请你原地删除重复出现的元素，使每个元素只出现一次，
 * 返回删除后数组的新长度。元素的相对顺序应该保持一致。然后返回 nums 中唯一元素的个数。
 * 
 * 考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
 * - 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。
 * - nums 的其余元素与 nums 的大小不重要。
 * - 返回 k 。
 * 
 * 示例 1:
 * 输入: nums = [1,1,2]
 * 输出: 2, nums = [1,2,_]
 * 解释: 函数应该返回新的长度 2，并且原数组 nums 的前两个元素被修改为 1, 2。
 * 不需要考虑数组中超出新长度后面的元素。
 * 
 * 示例 2:
 * 输入: nums = [0,0,1,1,1,2,2,3,3,4]
 * 输出: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 * 解释: 函数应该返回新的长度 5，并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 * 不需要考虑数组中超出新长度后面的元素。
 * 
 * 提示:
 * - 1 <= nums.length <= 3 * 10^4
 * - -100 <= nums[i] <= 100
 * - nums 已按非严格递增排列
 */

/*
@Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [26. 删除有序数组中的重复项]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {1, 1, 2};
    int k1 = solution.removeDuplicates(nums1);
    vector<int> result1(nums1.begin(), nums1.begin() + k1);
    RUN_TEST(result1, vector<int>({1, 2}), "测试用例 1: [1,1,2]");
    
    // 测试用例 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = solution.removeDuplicates(nums2);
    vector<int> result2(nums2.begin(), nums2.begin() + k2);
    RUN_TEST(result2, vector<int>({0, 1, 2, 3, 4}), 
             "测试用例 2: [0,0,1,1,1,2,2,3,3,4]");
    
    // 测试用例 3
    vector<int> nums3 = {1, 1, 1};
    int k3 = solution.removeDuplicates(nums3);
    vector<int> result3(nums3.begin(), nums3.begin() + k3);
    RUN_TEST(result3, vector<int>({1}), "测试用例 3: [1,1,1]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 原地删除有序数组中的重复项，使用双指针（快慢指针）技巧。
 * 
 * 核心思路：
 * 1. 慢指针指向当前不重复元素应该放置的位置
 * 2. 快指针遍历数组，寻找不重复的元素
 * 3. 当找到不重复元素时，放到慢指针位置，并移动慢指针
 * 
 * 【算法步骤】
 * 1. 如果数组为空，返回 0
 * 2. 初始化慢指针 slow = 0（第一个元素一定保留）
 * 3. 快指针 fast 从 1 开始遍历：
 *    - 如果 nums[fast] != nums[slow]，说明找到新的不重复元素
 *    - slow++，然后将 nums[fast] 复制到 nums[slow]
 * 4. 返回 slow + 1（数组长度）
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int removeDuplicates(vector<int>& nums) {
 *         if (nums.empty()) return 0;
 *         
 *         int slow = 0; // 慢指针
 *         
 *         for (int fast = 1; fast < nums.size(); fast++) {
 *             // 找到不重复的元素
 *             if (nums[fast] != nums[slow]) {
 *                 slow++;
 *                 nums[slow] = nums[fast];
 *             }
 *         }
 *         
 *         return slow + 1;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */