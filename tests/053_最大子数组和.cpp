/*
 * 题目编号: 53
 * 题目名称: 最大子数组和
 * 难度: 中等
 * 
 * 题目描述:
 * 给你一个整数数组 nums，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
 * 返回其最大和。
 * 
 * 子数组是数组中的一个连续部分。
 * 
 * 示例 1:
 * 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6
 * 
 * 示例 2:
 * 输入: nums = [1]
 * 输出: 1
 * 
 * 示例 3:
 * 输入: nums = [5,4,-1,7,8]
 * 输出: 23
 * 
 * 提示:
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * 
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 */

/*
@Solution
class Solution {
public:
    int maxSubArray(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [53. 最大子数组和]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    RUN_TEST(solution.maxSubArray(nums1), 6, 
             "测试用例 1: [-2,1,-3,4,-1,2,1,-5,4]");
    
    // 测试用例 2
    vector<int> nums2 = {1};
    RUN_TEST(solution.maxSubArray(nums2), 1, 
             "测试用例 2: [1]");
    
    // 测试用例 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    RUN_TEST(solution.maxSubArray(nums3), 23, 
             "测试用例 3: [5,4,-1,7,8]");
    
    // 测试用例 4：全是负数
    vector<int> nums4 = {-3, -2, -5, -1};
    RUN_TEST(solution.maxSubArray(nums4), -1, 
             "测试用例 4: [-3,-2,-5,-1]");
    
    // 测试用例 5：包含零
    vector<int> nums5 = {-2, 0, -1};
    RUN_TEST(solution.maxSubArray(nums5), 0, 
             "测试用例 5: [-2,0,-1]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 最大子数组和是一道经典的动态规划问题，也可以用贪心算法解决（Kadane算法）。
 * 
 * 核心思路（Kadane算法）：
 * 1. 维护两个变量：当前子数组和 currentSum 和最大子数组和 maxSum
 * 2. 遍历数组，对于每个元素，决定是将其加入当前子数组，还是从该元素重新开始
 * 3. 如果 currentSum < 0，说明前面的子数组对后续计算没有增益，应该重新开始
 * 
 * 【算法步骤】
 * 1. 初始化 maxSum = nums[0], currentSum = 0
 * 2. 遍历数组：
 *    - currentSum += nums[i]
 *    - 更新 maxSum = max(maxSum, currentSum)
 *    - 如果 currentSum < 0，重置为 0（重新开始）
 * 3. 返回 maxSum
 * 
 * 【参考解法1：贪心算法（Kadane）】
 * class Solution {
 * public:
 *     int maxSubArray(vector<int>& nums) {
 *         int maxSum = nums[0];
 *         int currentSum = 0;
 *         
 *         for (int num : nums) {
 *             currentSum += num;
 *             maxSum = max(maxSum, currentSum);
 *             
 *             // 如果当前和为负，重新开始
 *             if (currentSum < 0) {
 *                 currentSum = 0;
 *             }
 *         }
 *         
 *         return maxSum;
 *     }
 * };
 * 
 * 【参考解法2：动态规划】
 * class Solution {
 * public:
 *     int maxSubArray(vector<int>& nums) {
 *         int n = nums.size();
 *         // dp[i] 表示以 nums[i] 结尾的最大子数组和
 *         int dp = nums[0];
 *         int maxSum = nums[0];
 *         
 *         for (int i = 1; i < n; i++) {
 *             // 要么接着前面的子数组，要么重新开始
 *             dp = max(nums[i], dp + nums[i]);
 *             maxSum = max(maxSum, dp);
 *         }
 *         
 *         return maxSum;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
