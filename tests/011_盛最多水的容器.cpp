/*
 * 题目编号: 011
 * 题目名称: 盛最多水的容器
 * 难度: 中等
 * 
 * 题目描述:
 * 给定一个长度为 n 的整数数组 height。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i])。
 * 
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 返回容器可以储存的最大水量。
 * 
 * 说明：你不能倾斜容器。
 * 
 * 示例 1：
 * 输入：height = [1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。
 * 在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 示例 2：
 * 输入：height = [1,1]
 * 输出：1
 * 
 * 提示：
 * - n == height.length
 * - 2 <= n <= 10^5
 * - 0 <= height[i] <= 10^4
 */

/*
@Solution
class Solution {
public:
    int maxArea(vector<int>& height);
};
@EndSolution
*/

#include "../leetcode_framework.h"

#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [011. 盛最多水的容器]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    RUN_TEST(solution.maxArea(height1), 49, "测试用例 1: [1,8,6,2,5,4,8,3,7]");
    
    // 测试用例 2
    vector<int> height2 = {1,1};
    RUN_TEST(solution.maxArea(height2), 1, "测试用例 2: [1,1]");
    
    // 测试用例 3
    vector<int> height3 = {4,3,2,1,4};
    RUN_TEST(solution.maxArea(height3), 16, "测试用例 3: [4,3,2,1,4]");
    
    // 测试用例 4
    vector<int> height4 = {1,2,1};
    RUN_TEST(solution.maxArea(height4), 2, "测试用例 4: [1,2,1]");
    
    // 测试用例 5: 递增
    vector<int> height5 = {1,2,3,4,5};
    RUN_TEST(solution.maxArea(height5), 6, "测试用例 5: [1,2,3,4,5]");
    
    // 测试用例 6: 递减
    vector<int> height6 = {5,4,3,2,1};
    RUN_TEST(solution.maxArea(height6), 6, "测试用例 6: [5,4,3,2,1]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的**双指针**问题，面试超高频（字节、腾讯、阿里必考）。
 * 
 * 核心思想：
 * - 容器的面积 = min(左边高度, 右边高度) × 宽度
 * - 使用双指针从两端向中间移动，每次移动较矮的那一边
 * 
 * 为什么要移动较矮的一边？
 * - 因为面积由较矮的边决定
 * - 移动较高的边，宽度减小，高度不可能变高，面积一定变小
 * - 移动较矮的边，虽然宽度减小，但高度可能变高，面积可能变大
 * 
 * 【算法步骤】
 * 1. 初始化左指针 left = 0，右指针 right = n - 1
 * 2. 初始化最大面积 maxArea = 0
 * 3. 当 left < right 时：
 *    - 计算当前面积 = min(height[left], height[right]) × (right - left)
 *    - 更新最大面积
 *    - 如果 height[left] < height[right]，left++（移动较矮的边）
 *    - 否则 right--
 * 4. 返回最大面积
 * 
 * 【参考解法】
 * 
 * // 方法1：双指针（贪心）
 * class Solution {
 * public:
 *     int maxArea(vector<int>& height) {
 *         int left = 0, right = height.size() - 1;
 *         int maxArea = 0;
 *         
 *         while (left < right) {
 *             // 计算当前面积（宽度 × 高度）
 *             int width = right - left;
 *             int h = min(height[left], height[right]);
 *             int area = width * h;
 *             
 *             // 更新最大面积
 *             maxArea = max(maxArea, area);
 *             
 *             // 移动较矮的那一边
 *             if (height[left] < height[right]) {
 *                 left++;
 *             } else {
 *                 right--;
 *             }
 *         }
 *         
 *         return maxArea;
 *     }
 * };
 * 
 * // 方法2：双指针（优化版）
 * class Solution {
 * public:
 *     int maxArea(vector<int>& height) {
 *         int left = 0, right = height.size() - 1;
 *         int maxArea = 0;
 *         
 *         while (left < right) {
 *             // 直接计算面积
 *             int h = min(height[left], height[right]);
 *             maxArea = max(maxArea, h * (right - left));
 *             
 *             // 移动较矮的边，并跳过更矮的柱子
 *             if (height[left] < height[right]) {
 *                 left++;
 *             } else {
 *                 right--;
 *             }
 *         }
 *         
 *         return maxArea;
 *     }
 * };
 * 
 * 【复杂度分析】
 * - 时间复杂度：O(n) - 每个元素最多被访问一次
 * - 空间复杂度：O(1) - 只使用常数额外空间
 * 
 * 【关键点】
 * 1. **贪心思想**：总是移动较矮的边
 * 2. **双指针技巧**：从两端向中间移动
 * 3. **面积计算**：min(左高, 右高) × 宽度
 * 4. 不需要遍历所有组合，O(n) 时间就能找到最优解
 * 
 * 【证明正确性】
 * 假设最优解是 (i, j)，其中 i < j：
 * - 我们的算法一定会遍历到这个状态
 * - 因为我们总是移动较矮的边，不会错过任何可能更大的面积
 * 
 * 【对比暴力解法】
 * 暴力解法：枚举所有可能的两条线，时间复杂度 O(n²)
 * 双指针：O(n) 时间找到最优解
 * 
 * 【面试高频程度】⭐⭐⭐⭐⭐
 * - 字节跳动：超高频
 * - 腾讯：高频
 * - 阿里：高频
 * - 美团：高频
 * 
 * 【相关题目】
 * - LeetCode 42: 接雨水（更难的双指针题）
 * - LeetCode 15: 三数之和（双指针）
 */

