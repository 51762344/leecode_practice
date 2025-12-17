/*
 * 题目编号: 136
 * 题目名称: 只出现一次的数字
 * 难度: 简单
 * 
 * 题目描述:
 * 给你一个非空整数数组 nums，除了某个元素只出现一次以外，其余每个元素均出现两次。
 * 找出那个只出现了一次的元素。
 * 
 * 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 * 
 * 示例 1:
 * 输入: nums = [2,2,1]
 * 输出: 1
 * 
 * 示例 2:
 * 输入: nums = [4,1,2,1,2]
 * 输出: 4
 * 
 * 示例 3:
 * 输入: nums = [1]
 * 输出: 1
 * 
 * 提示:
 * - 1 <= nums.length <= 3 * 10^4
 * - -3 * 10^4 <= nums[i] <= 3 * 10^4
 * - 除了某个元素只出现一次以外，其余每个元素均出现两次
 */

/*
@Solution
class Solution {
public:
    int singleNumber(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [136. 只出现一次的数字]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {2, 2, 1};
    RUN_TEST(solution.singleNumber(nums1), 1, "测试用例 1: [2,2,1]");
    
    // 测试用例 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    RUN_TEST(solution.singleNumber(nums2), 4, "测试用例 2: [4,1,2,1,2]");
    
    // 测试用例 3
    vector<int> nums3 = {1};
    RUN_TEST(solution.singleNumber(nums3), 1, "测试用例 3: [1]");
    
    // 测试用例 4
    vector<int> nums4 = {-1, -1, -2};
    RUN_TEST(solution.singleNumber(nums4), -2, "测试用例 4: [-1,-1,-2]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 找出数组中只出现一次的数字，其他数字都出现两次。要求线性时间和常量空间。
 * 
 * 核心思路：
 * 使用异或（XOR）运算的性质：
 * 1. a ^ a = 0（相同的数异或为0）
 * 2. a ^ 0 = a（任何数与0异或为自己）
 * 3. 异或满足交换律和结合律
 * 
 * 所有数字异或后，成对的数字会相互抵消为0，最后剩下的就是只出现一次的数字。
 * 
 * 【算法步骤】
 * 1. 初始化 result = 0
 * 2. 遍历数组，将所有数字异或到 result 上
 * 3. 返回 result
 * 
 * 【举例说明】
 * nums = [4, 1, 2, 1, 2]
 * result = 0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2
 *        = 4 ^ (1 ^ 1) ^ (2 ^ 2)
 *        = 4 ^ 0 ^ 0
 *        = 4
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int singleNumber(vector<int>& nums) {
 *         int result = 0;
 *         
 *         for (int num : nums) {
 *             result ^= num;  // 异或运算
 *         }
 *         
 *         return result;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 
 * 【知识点】
 * 异或运算的常见应用：
 * - 交换两个数：a ^= b; b ^= a; a ^= b;
 * - 判断两个数是否相等：a ^ b == 0
 * - 找出不同的元素
 */