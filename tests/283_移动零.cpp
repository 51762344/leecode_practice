/*
 * 题目编号: 283
 * 题目名称: 移动零
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 请注意，必须在不复制数组的情况下原地对数组进行操作。
 * 
 * 示例 1:
 * 输入: nums = [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 示例 2:
 * 输入: nums = [0]
 * 输出: [0]
 * 
 * 提示:
 * - 1 <= nums.length <= 10^4
 * - -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 进阶：你能尽量减少完成的操作次数吗？
 */

/*
@Solution
class Solution {
public:
    void moveZeroes(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [283. 移动零]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    vector<int> expected1 = {1, 3, 12, 0, 0};
    solution.moveZeroes(nums1);
    RUN_TEST(nums1, expected1, 
             "测试用例 1: [0,1,0,3,12]");
    
    // 测试用例 2
    vector<int> nums2 = {0};
    vector<int> expected2 = {0};
    solution.moveZeroes(nums2);
    RUN_TEST(nums2, expected2, 
             "测试用例 2: [0]");
    
    // 测试用例 3：没有零
    vector<int> nums3 = {1, 2, 3};
    vector<int> expected3 = {1, 2, 3};
    solution.moveZeroes(nums3);
    RUN_TEST(nums3, expected3, 
             "测试用例 3: [1,2,3]");
    
    // 测试用例 4：全是零
    vector<int> nums4 = {0, 0, 0};
    vector<int> expected4 = {0, 0, 0};
    solution.moveZeroes(nums4);
    RUN_TEST(nums4, expected4, 
             "测试用例 4: [0,0,0]");
    
    // 测试用例 5：零在开头
    vector<int> nums5 = {0, 0, 1, 2};
    vector<int> expected5 = {1, 2, 0, 0};
    solution.moveZeroes(nums5);
    RUN_TEST(nums5, expected5, 
             "测试用例 5: [0,0,1,2]");
    
    // 测试用例 6：零在末尾
    vector<int> nums6 = {1, 2, 0, 0};
    vector<int> expected6 = {1, 2, 0, 0};
    solution.moveZeroes(nums6);
    RUN_TEST(nums6, expected6, 
             "测试用例 6: [1,2,0,0]");
    
    // 测试用例 7：交替出现
    vector<int> nums7 = {1, 0, 2, 0, 3};
    vector<int> expected7 = {1, 2, 3, 0, 0};
    solution.moveZeroes(nums7);
    RUN_TEST(nums7, expected7, 
             "测试用例 7: [1,0,2,0,3]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 将所有0移动到数组末尾，保持非零元素的相对顺序。使用双指针技巧。
 * 
 * 核心思路：
 * 使用快慢指针：
 * - 慢指针指向下一个非零元素应该放置的位置
 * - 快指针遍历数组，寻找非零元素
 * - 遍历完成后，将慢指针后面的位置都填充为0
 * 
 * 【算法步骤】
 * 1. 初始化慢指针 slow = 0
 * 2. 快指针遍历数组：
 *    - 如果 nums[fast] != 0
 *    - 将 nums[fast] 移动到 nums[slow]
 *    - slow++
 * 3. 将 [slow, n) 范围内的元素都设为0
 * 
 * 【优化：一次遍历，减少写操作】
 * 如果 slow == fast，说明前面没有0，不需要赋值。
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     void moveZeroes(vector<int>& nums) {
 *         int slow = 0; // 下一个非零元素应该放置的位置
 *         
 *         // 第一遍：将所有非零元素移到前面
 *         for (int fast = 0; fast < nums.size(); fast++) {
 *             if (nums[fast] != 0) {
 *                 nums[slow] = nums[fast];
 *                 slow++;
 *             }
 *         }
 *         
 *         // 第二遍：将剩余位置填充为0
 *         for (int i = slow; i < nums.size(); i++) {
 *             nums[i] = 0;
 *         }
 *     }
 * };
 * 
 * 【优化解法：减少写操作】
 * class Solution {
 * public:
 *     void moveZeroes(vector<int>& nums) {
 *         int slow = 0;
 *         
 *         for (int fast = 0; fast < nums.size(); fast++) {
 *             if (nums[fast] != 0) {
 *                 // 只有当 slow != fast 时才需要交换
 *                 if (slow != fast) {
 *                     swap(nums[slow], nums[fast]);
 *                 }
 *                 slow++;
 *             }
 *         }
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 
 * 【类似题目】
 * - 27. 移除元素
 * - 26. 删除有序数组中的重复项
 * 都可以用类似的双指针技巧解决。
 */
