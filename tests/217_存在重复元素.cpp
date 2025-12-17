/*
 * 题目编号: 217
 * 题目名称: 存在重复元素
 * 难度: 简单
 * 
 * 题目描述:
 * 给你一个整数数组 nums。如果任一值在数组中出现至少两次，返回 true；
 * 如果数组中每个元素互不相同，返回 false。
 * 
 * 示例 1:
 * 输入: nums = [1,2,3,1]
 * 输出: true
 * 
 * 示例 2:
 * 输入: nums = [1,2,3,4]
 * 输出: false
 * 
 * 示例 3:
 * 输入: nums = [1,1,1,3,3,4,3,2,4,2]
 * 输出: true
 * 
 * 提示:
 * - 1 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 */

/*
@Solution
class Solution {
public:
    bool containsDuplicate(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [217. 存在重复元素]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {1, 2, 3, 1};
    RUN_TEST(solution.containsDuplicate(nums1), true, 
             "测试用例 1: [1,2,3,1]");
    
    // 测试用例 2
    vector<int> nums2 = {1, 2, 3, 4};
    RUN_TEST(solution.containsDuplicate(nums2), false, 
             "测试用例 2: [1,2,3,4]");
    
    // 测试用例 3
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    RUN_TEST(solution.containsDuplicate(nums3), true, 
             "测试用例 3: [1,1,1,3,3,4,3,2,4,2]");
    
    // 测试用例 4: 单个元素
    vector<int> nums4 = {1};
    RUN_TEST(solution.containsDuplicate(nums4), false, 
             "测试用例 4: [1] (单个元素)");
    
    // 测试用例 5: 两个相同元素
    vector<int> nums5 = {5, 5};
    RUN_TEST(solution.containsDuplicate(nums5), true, 
             "测试用例 5: [5,5]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这道题要求判断数组中是否存在重复元素。有多种解法，从暴力到优化。
 * 
 * 核心思路：
 * 1. 使用哈希表（unordered_set）记录已经见过的元素
 * 2. 遍历数组，如果元素已存在于哈希表中，返回 true
 * 3. 否则将元素加入哈希表
 * 4. 遍历结束后返回 false
 * 
 * 【算法步骤】
 * 1. 创建哈希集合 set
 * 2. 遍历数组中的每个元素：
 *    - 如果元素在 set 中，返回 true
 *    - 否则将元素加入 set
 * 3. 遍历完成，返回 false
 * 
 * 【参考解法】
 * 
 * // 方法1：哈希表（最优解）
 * class Solution {
 * public:
 *     bool containsDuplicate(vector<int>& nums) {
 *         unordered_set<int> seen;
 *         
 *         for (int num : nums) {
 *             // 如果元素已存在，说明有重复
 *             if (seen.find(num) != seen.end()) {
 *                 return true;
 *             }
 *             seen.insert(num);
 *         }
 *         
 *         return false;
 *     }
 * };
 * 
 * // 方法2：排序后比较相邻元素
 * class Solution {
 * public:
 *     bool containsDuplicate(vector<int>& nums) {
 *         sort(nums.begin(), nums.end());
 *         
 *         for (int i = 1; i < nums.size(); i++) {
 *             if (nums[i] == nums[i-1]) {
 *                 return true;
 *             }
 *         }
 *         
 *         return false;
 *     }
 * };
 * 
 * // 方法3：利用 set 的去重特性
 * class Solution {
 * public:
 *     bool containsDuplicate(vector<int>& nums) {
 *         return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（哈希表）：
 * - 时间复杂度：O(n) - 遍历一次数组，哈希表操作平均 O(1)
 * - 空间复杂度：O(n) - 最坏情况下需要存储所有元素
 * 
 * 方法2（排序）：
 * - 时间复杂度：O(n log n) - 排序的时间
 * - 空间复杂度：O(1) 或 O(log n) - 取决于排序算法
 * 
 * 方法3（set 去重）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(n)
 * 
 * 【知识点】
 * - 哈希表的应用
 * - 时间和空间的权衡
 * - 排序的应用
 */
