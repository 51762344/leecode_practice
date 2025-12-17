/*
 * 题目编号: 88
 * 题目名称: 合并两个有序数组
 * 难度: 简单
 * 
 * 题目描述:
 * 给你两个按非递减顺序排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n，
 * 分别表示 nums1 和 nums2 中的元素数目。
 * 
 * 请你合并 nums2 到 nums1 中，使合并后的数组同样按非递减顺序排列。
 * 
 * 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
 * 为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，
 * 后 n 个元素为 0，应忽略。nums2 的长度为 n。
 * 
 * 示例 1:
 * 输入: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 输出: [1,2,2,3,5,6]
 * 解释: 需要合并 [1,2,3] 和 [2,5,6]。
 * 
 * 示例 2:
 * 输入: nums1 = [1], m = 1, nums2 = [], n = 0
 * 输出: [1]
 * 
 * 示例 3:
 * 输入: nums1 = [0], m = 0, nums2 = [1], n = 1
 * 输出: [1]
 * 
 * 提示:
 * - nums1.length == m + n
 * - nums2.length == n
 * - 0 <= m, n <= 200
 * - 1 <= m + n <= 200
 */

/*
@Solution
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [88. 合并两个有序数组]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2_1 = {2, 5, 6};
    vector<int> expected1 = {1, 2, 2, 3, 5, 6};
    solution.merge(nums1_1, 3, nums2_1, 3);
    RUN_TEST(nums1_1, expected1, "测试用例 1: [1,2,3] + [2,5,6]");
    
    // 测试用例 2
    vector<int> nums1_2 = {1};
    vector<int> nums2_2 = {};
    vector<int> expected2 = {1};
    solution.merge(nums1_2, 1, nums2_2, 0);
    RUN_TEST(nums1_2, expected2, "测试用例 2: [1] + []");
    
    // 测试用例 3
    vector<int> nums1_3 = {0};
    vector<int> nums2_3 = {1};
    vector<int> expected3 = {1};
    solution.merge(nums1_3, 0, nums2_3, 1);
    RUN_TEST(nums1_3, expected3, "测试用例 3: [] + [1]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 合并两个有序数组到 nums1 中。关键是要原地操作，避免使用额外空间。
 * 
 * 核心思路：
 * 从后向前填充，避免覆盖 nums1 中还未处理的元素。
 * 使用三个指针：
 * - p1: nums1 有效元素的末尾（m-1）
 * - p2: nums2 的末尾（n-1）
 * - p: nums1 总长度的末尾（m+n-1）
 * 
 * 【算法步骤】
 * 1. 初始化三个指针：p1 = m-1, p2 = n-1, p = m+n-1
 * 2. 从后向前比较 nums1[p1] 和 nums2[p2]：
 *    - 将较大的元素放到 nums1[p]
 *    - 移动相应指针
 * 3. 如果 nums2 还有剩余元素，复制到 nums1
 * 4. 如果 nums1 还有剩余元素，已经在正确位置，不需要处理
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
 *         int p1 = m - 1;     // nums1 有效元素的末尾
 *         int p2 = n - 1;     // nums2 的末尾
 *         int p = m + n - 1;  // nums1 总长度的末尾
 *         
 *         // 从后向前填充
 *         while (p1 >= 0 && p2 >= 0) {
 *             if (nums1[p1] > nums2[p2]) {
 *                 nums1[p] = nums1[p1];
 *                 p1--;
 *             } else {
 *                 nums1[p] = nums2[p2];
 *                 p2--;
 *             }
 *             p--;
 *         }
 *         
 *         // 如果 nums2 还有剩余元素，复制到 nums1
 *         // （如果 nums1 还有剩余，已经在正确位置）
 *         while (p2 >= 0) {
 *             nums1[p] = nums2[p2];
 *             p2--;
 *             p--;
 *         }
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(m + n)
 * 空间复杂度：O(1)
 */
