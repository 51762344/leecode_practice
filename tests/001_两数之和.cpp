/*
 * 题目编号: 1
 * 题目名称: 两数之和
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target
 * 的那两个整数，并返回它们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 * 
 * 示例 1:
 * 输入: nums = [2,7,11,15], target = 9
 * 输出: [0,1]
 * 解释: 因为 nums[0] + nums[1] == 9，返回 [0, 1]。
 * 
 * 示例 2:
 * 输入: nums = [3,2,4], target = 6
 * 输出: [1,2]
 * 
 * 示例 3:
 * 输入: nums = [3,3], target = 6
 * 输出: [0,1]
 * 
 * 提示:
 * - 2 <= nums.length <= 10^4
 * - -10^9 <= nums[i] <= 10^9
 * - -10^9 <= target <= 10^9
 * - 只会存在一个有效答案
 */

/*
@Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [1. 两数之和]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> expected1 = {0, 1};
    RUN_TEST(solution.twoSum(nums1, 9), expected1, 
             "测试用例 1: [2,7,11,15], target=9");
    
    // 测试用例 2
    vector<int> nums2 = {3, 2, 4};
    vector<int> expected2 = {1, 2};
    RUN_TEST(solution.twoSum(nums2, 6), expected2, 
             "测试用例 2: [3,2,4], target=6");
    
    // 测试用例 3
    vector<int> nums3 = {3, 3};
    vector<int> expected3 = {0, 1};
    RUN_TEST(solution.twoSum(nums3, 6), expected3, 
             "测试用例 3: [3,3], target=6");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这道题要求在数组中找到两个数，使它们的和等于目标值。最直观的方法是双重循环暴力搜索，
 * 但时间复杂度为 O(n²)。更优的方法是使用哈希表（unordered_map）来优化。
 * 
 * 核心思路：
 * 1. 遍历数组时，对于每个元素 nums[i]，计算 target - nums[i]
 * 2. 在哈希表中查找是否存在这个差值
 * 3. 如果存在，返回两个下标；如果不存在，将当前元素及其下标存入哈希表
 * 
 * 【算法步骤】
 * 1. 创建哈希表 map<值, 下标>
 * 2. 遍历数组：
 *    - 计算 complement = target - nums[i]
 *    - 如果 complement 在哈希表中，返回 {map[complement], i}
 *    - 否则，将 nums[i] 和 i 存入哈希表
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     vector<int> twoSum(vector<int>& nums, int target) {
 *         unordered_map<int, int> map; // 值 -> 下标
 *         
 *         for (int i = 0; i < nums.size(); i++) {
 *             int complement = target - nums[i];
 *             
 *             // 如果找到了互补的数
 *             if (map.find(complement) != map.end()) {
 *                 return {map[complement], i};
 *             }
 *             
 *             // 将当前数字存入哈希表
 *             map[nums[i]] = i;
 *         }
 *         
 *         return {}; // 题目保证有解，这里不会执行到
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n) - 只需遍历一次数组
 * 空间复杂度：O(n) - 哈希表最多存储 n 个元素
 */
