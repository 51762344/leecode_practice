/*
 * 题目编号: 416
 * 题目名称: 分割等和子集
 * 难度: 中等
 * 
 * 题目描述:
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，
 * 使得两个子集的元素和相等。
 * 
 * 示例 1:
 * 输入: nums = [1,5,11,5]
 * 输出: true
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11]。
 * 
 * 示例 2:
 * 输入: nums = [1,2,3,5]
 * 输出: false
 * 解释: 数组不能分割成两个元素和相等的子集。
 * 
 * 提示:
 * - 1 <= nums.length <= 200
 * - 1 <= nums[i] <= 100
 */

/*
@Solution
class Solution {
public:
    bool canPartition(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [416. 分割等和子集]..." << endl;
    
    // 测试用例 1
    vector<int> nums1 = {1,5,11,5};
    bool expected1 = true;
    bool result1 = solution.canPartition(nums1);
    cout << "测试用例 1: nums=[1,5,11,5], 期望=" << (expected1 ? "true" : "false") << ", 实际=" << (result1 ? "true" : "false");
    if (result1 == expected1) {
        cout << " ✓ 通过" << endl;
    } else {
        cout << " ✗ 失败" << endl;
    }
    
    // 测试用例 2
    vector<int> nums2 = {1,2,3,5};
    bool expected2 = false;
    bool result2 = solution.canPartition(nums2);
    cout << "测试用例 2: nums=[1,2,3,5], 期望=" << (expected2 ? "true" : "false") << ", 实际=" << (result2 ? "true" : "false");
    if (result2 == expected2) {
        cout << " ✓ 通过" << endl;
    } else {
        cout << " ✗ 失败" << endl;
    }
    
    cout << "测试完成。" << endl;
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的动态规划题目，需要判断数组能否分割成两个和相等的子集。
 * 这等价于是否存在一个子集，其和等于总和的一半。
 * 
 * 核心思路：
 * 使用0/1背包的思路，DP数组 dp[j] 表示是否能凑成和为 j。
 * 目标是判断是否能凑成 sum/2。
 * 状态转移：对于每个数，更新DP数组。
 * 
 * 【算法步骤】
 * 1. 计算数组总和 sum
 * 2. 如果 sum 为奇数，返回 false
 * 3. 目标和 target = sum / 2
 * 4. 初始化DP数组，大小为 target + 1，初始 dp[0] = true
 * 5. 遍历每个数字 num：
 *    - 从后往前更新DP数组（0/1背包）
 *    - for (int j = target; j >= num; j--) {
 *        dp[j] = dp[j] || dp[j - num];
 *      }
 * 6. 返回 dp[target]
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     bool canPartition(vector<int>& nums) {
 *         int sum = 0;
 *         for (int num : nums) sum += num;
 *         if (sum % 2 != 0) return false;
 *         
 *         int target = sum / 2;
 *         vector<bool> dp(target + 1, false);
 *         dp[0] = true;
 *         
 *         for (int num : nums) {
 *             for (int j = target; j >= num; j--) {
 *                 dp[j] = dp[j] || dp[j - num];
 *             }
 *         }
 *         
 *         return dp[target];
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n * target) - n为数组长度，target为总和的一半
 * 空间复杂度：O(target) - 使用了一维DP数组
 */