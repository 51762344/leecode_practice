/*
 * 题目编号: 268
 * 题目名称: 丢失的数字
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个包含 [0, n] 中 n 个数的数组 nums，找出 [0, n] 这个范围内没有出现在数组中的那个数。
 * 
 * 示例 1:
 * 输入: nums = [3,0,1]
 * 输出: 2
 * 解释: n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。
 * 2 是丢失的数字，因为它没有出现在 nums 中。
 * 
 * 示例 2:
 * 输入: nums = [0,1]
 * 输出: 2
 * 解释: n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。
 * 2 是丢失的数字，因为它没有出现在 nums 中。
 * 
 * 示例 3:
 * 输入: nums = [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 解释: n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。
 * 8 是丢失的数字，因为它没有出现在 nums 中。
 * 
 * 提示:
 * - n == nums.length
 * - 1 <= n <= 10^4
 * - 0 <= nums[i] <= n
 * - nums 中的所有数字都独一无二
 * 
 * 进阶: 你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题？
 */

/*
@Solution
class Solution {
public:
    int missingNumber(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [268. 丢失的数字]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {3, 0, 1};
    RUN_TEST(solution.missingNumber(nums1), 2, "测试用例 1: [3,0,1]");
    
    // 测试用例 2
    vector<int> nums2 = {0, 1};
    RUN_TEST(solution.missingNumber(nums2), 2, "测试用例 2: [0,1]");
    
    // 测试用例 3
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    RUN_TEST(solution.missingNumber(nums3), 8, "测试用例 3: [9,6,4,2,3,5,7,0,1]");
    
    // 测试用例 4: 缺少 0
    vector<int> nums4 = {1, 2, 3};
    RUN_TEST(solution.missingNumber(nums4), 0, "测试用例 4: [1,2,3] (缺少0)");
    
    // 测试用例 5: 缺少最后一个
    vector<int> nums5 = {0, 1, 2, 3};
    RUN_TEST(solution.missingNumber(nums5), 4, "测试用例 5: [0,1,2,3] (缺少4)");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这道题有多种解法，从暴力到数学技巧。核心是利用数组长度和数组元素的关系。
 * 
 * 核心思路：
 * 1. 数组长度为 n，应该包含 [0, n] 中的 n 个数
 * 2. 缺少一个数字，可以用数学方法找出
 * 
 * 【算法步骤】
 * 
 * 方法1（求和公式）：
 * 1. 计算 0 到 n 的和：sum = n * (n + 1) / 2
 * 2. 计算数组实际的和
 * 3. 两者之差就是缺失的数字
 * 
 * 方法2（异或）：
 * 1. 利用异或的性质：a ^ a = 0, a ^ 0 = a
 * 2. 将 [0, n] 所有数和数组中所有数进行异或
 * 3. 相同的数会被消去，剩下的就是缺失的数
 * 
 * 【参考解法】
 * 
 * // 方法1：求和公式
 * class Solution {
 * public:
 *     int missingNumber(vector<int>& nums) {
 *         int n = nums.size();
 *         
 *         // 计算 0 到 n 的和
 *         int expectedSum = n * (n + 1) / 2;
 *         
 *         // 计算数组实际的和
 *         int actualSum = 0;
 *         for (int num : nums) {
 *             actualSum += num;
 *         }
 *         
 *         // 返回差值
 *         return expectedSum - actualSum;
 *     }
 * };
 * 
 * // 方法2：异或（XOR）
 * class Solution {
 * public:
 *     int missingNumber(vector<int>& nums) {
 *         int n = nums.size();
 *         int result = n;  // 初始化为 n
 *         
 *         // 异或所有索引和对应的值
 *         for (int i = 0; i < n; i++) {
 *             result ^= i ^ nums[i];
 *         }
 *         
 *         return result;
 *     }
 * };
 * 
 * // 方法3：哈希表（空间换时间）
 * class Solution {
 * public:
 *     int missingNumber(vector<int>& nums) {
 *         unordered_set<int> numSet(nums.begin(), nums.end());
 *         
 *         int n = nums.size();
 *         for (int i = 0; i <= n; i++) {
 *             if (numSet.find(i) == numSet.end()) {
 *                 return i;
 *             }
 *         }
 *         
 *         return -1;  // 不会执行到这里
 *     }
 * };
 * 
 * // 方法4：排序后查找
 * class Solution {
 * public:
 *     int missingNumber(vector<int>& nums) {
 *         sort(nums.begin(), nums.end());
 *         
 *         int n = nums.size();
 *         
 *         // 检查是否缺少 0
 *         if (nums[0] != 0) return 0;
 *         
 *         // 检查是否缺少 n
 *         if (nums[n-1] != n) return n;
 *         
 *         // 检查中间
 *         for (int i = 1; i < n; i++) {
 *             if (nums[i] != nums[i-1] + 1) {
 *                 return nums[i-1] + 1;
 *             }
 *         }
 *         
 *         return -1;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（求和）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(1)
 * - 注意：需要注意整数溢出（对于大数据）
 * 
 * 方法2（异或）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(1)
 * - 优点：不会溢出
 * 
 * 方法3（哈希表）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(n)
 * 
 * 方法4（排序）：
 * - 时间复杂度：O(n log n)
 * - 空间复杂度：O(1) 或 O(log n)
 * 
 * 【知识点】
 * - 数学技巧（高斯求和公式）
 * - 异或运算的性质
 * - 哈希表的应用
 * - 排序的应用
 * 
 * 【推荐】
 * 方法1和方法2都是最优解，面试时可以先说方法1，然后提到异或方法避免溢出。
 */
