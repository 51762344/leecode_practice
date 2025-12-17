/*
 * 题目编号: 169
 * 题目名称: 多数元素
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个大小为 n 的数组 nums，返回其中的多数元素。
 * 多数元素是指在数组中出现次数大于 ⌊n/2⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 示例 1:
 * 输入: nums = [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 输入: nums = [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 提示:
 * - n == nums.length
 * - 1 <= n <= 5 * 10^4
 * - -10^9 <= nums[i] <= 10^9
 * 
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 */

/*
@Solution
class Solution {
public:
    int majorityElement(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [169. 多数元素]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {3, 2, 3};
    RUN_TEST(solution.majorityElement(nums1), 3, 
             "测试用例 1: [3,2,3]");
    
    // 测试用例 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    RUN_TEST(solution.majorityElement(nums2), 2, 
             "测试用例 2: [2,2,1,1,1,2,2]");
    
    // 测试用例 3：只有一个元素
    vector<int> nums3 = {1};
    RUN_TEST(solution.majorityElement(nums3), 1, 
             "测试用例 3: [1]");
    
    // 测试用例 4：所有元素相同
    vector<int> nums4 = {5, 5, 5, 5};
    RUN_TEST(solution.majorityElement(nums4), 5, 
             "测试用例 4: [5,5,5,5]");
    
    // 测试用例 5：多数元素在开头
    vector<int> nums5 = {6, 6, 6, 7, 7};
    RUN_TEST(solution.majorityElement(nums5), 6, 
             "测试用例 5: [6,6,6,7,7]");
    
    // 测试用例 6：多数元素在末尾
    vector<int> nums6 = {1, 2, 2, 2, 2};
    RUN_TEST(solution.majorityElement(nums6), 2, 
             "测试用例 6: [1,2,2,2,2]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 找出数组中的多数元素（出现次数 > n/2）。有多种解法，最优解是摩尔投票算法。
 * 
 * 核心思路（摩尔投票算法 Boyer-Moore Voting）：
 * 把多数元素想象成"国王"，其他元素是"平民"。
 * 国王和平民两两抵消，因为国王数量 > n/2，最后一定剩下国王。
 * 
 * 【算法步骤】
 * 1. 初始化候选人 candidate 和计数器 count = 0
 * 2. 遍历数组：
 *    - 如果 count == 0，将当前元素设为候选人
 *    - 如果当前元素 == 候选人，count++
 *    - 否则 count--（抵消）
 * 3. 返回候选人（题目保证存在多数元素）
 * 
 * 【举例说明】
 * nums = [2, 2, 1, 1, 1, 2, 2]
 * 
 * i=0: num=2, count=0 -> candidate=2, count=1
 * i=1: num=2, count=1 -> count=2
 * i=2: num=1, count=2 -> count=1 (抵消)
 * i=3: num=1, count=1 -> count=0 (抵消)
 * i=4: num=1, count=0 -> candidate=1, count=1
 * i=5: num=2, count=1 -> count=0 (抵消)
 * i=6: num=2, count=0 -> candidate=2, count=1
 * 
 * 返回 2
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int majorityElement(vector<int>& nums) {
 *         int candidate = 0;
 *         int count = 0;
 *         
 *         // 摩尔投票
 *         for (int num : nums) {
 *             if (count == 0) {
 *                 candidate = num;
 *             }
 *             count += (num == candidate) ? 1 : -1;
 *         }
 *         
 *         return candidate;
 *     }
 * };
 * 
 * 【其他解法】
 * 1. 哈希表统计：O(n) 时间，O(n) 空间
 * 2. 排序：O(n log n) 时间，排序后中间元素一定是多数元素
 * 3. 分治法：O(n log n) 时间
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
