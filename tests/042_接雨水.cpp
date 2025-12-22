/*
 * 题目编号: 042
 * 题目名称: 接雨水
 * 难度: 困难
 * 
 * 题目描述:
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 示例 1：
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，
 * 在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 * 
 * 示例 2：
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 提示：
 * - n == height.length
 * - 1 <= n <= 2 * 10^4
 * - 0 <= height[i] <= 10^5
 */

/*
@Solution
class Solution {
public:
    int trap(vector<int>& height);
};
@EndSolution
*/

#include "../leetcode_framework.h"

#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [042. 接雨水]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    RUN_TEST(solution.trap(height1), 6, "测试用例 1: [0,1,0,2,1,0,1,3,2,1,2,1]");
    
    // 测试用例 2
    vector<int> height2 = {4,2,0,3,2,5};
    RUN_TEST(solution.trap(height2), 9, "测试用例 2: [4,2,0,3,2,5]");
    
    // 测试用例 3: 没有雨水
    vector<int> height3 = {1,2,3,4,5};
    RUN_TEST(solution.trap(height3), 0, "测试用例 3: [1,2,3,4,5] - 递增无雨水");
    
    // 测试用例 4: 简单情况
    vector<int> height4 = {3,0,2};
    RUN_TEST(solution.trap(height4), 2, "测试用例 4: [3,0,2]");
    
    // 测试用例 5: 单个柱子
    vector<int> height5 = {5};
    RUN_TEST(solution.trap(height5), 0, "测试用例 5: [5] - 单个柱子");
    
    // 测试用例 6: 两个柱子
    vector<int> height6 = {3,3};
    RUN_TEST(solution.trap(height6), 0, "测试用例 6: [3,3] - 两个柱子");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的**困难**题目，面试**超高频**（字节跳动、腾讯、阿里必考）。
 * 
 * 核心思想：
 * 对于每个位置，能接的雨水量 = min(左边最高, 右边最高) - 当前高度
 * 
 * 关键问题：如何高效地找到每个位置左右两边的最大值？
 * 
 * 【算法步骤】
 * 
 * 方法1：动态规划（最易理解）
 * 1. 预处理左侧最大值数组 leftMax[]
 * 2. 预处理右侧最大值数组 rightMax[]
 * 3. 遍历每个位置，计算雨水量
 * 
 * 方法2：双指针（最优解）
 * 1. 使用 left 和 right 两个指针从两端向中间移动
 * 2. 维护 leftMax 和 rightMax
 * 3. 每次移动较矮的一边
 * 
 * 方法3：单调栈
 * 1. 维护一个单调递减栈
 * 2. 遇到比栈顶高的柱子时，计算可以接的雨水
 * 
 * 【参考解法】
 * 
 * // 方法1：动态规划（最易理解）
 * class Solution {
 * public:
 *     int trap(vector<int>& height) {
 *         int n = height.size();
 *         if (n <= 2) return 0;
 *         
 *         // 预处理左侧最大值
 *         vector<int> leftMax(n);
 *         leftMax[0] = height[0];
 *         for (int i = 1; i < n; i++) {
 *             leftMax[i] = max(leftMax[i-1], height[i]);
 *         }
 *         
 *         // 预处理右侧最大值
 *         vector<int> rightMax(n);
 *         rightMax[n-1] = height[n-1];
 *         for (int i = n-2; i >= 0; i--) {
 *             rightMax[i] = max(rightMax[i+1], height[i]);
 *         }
 *         
 *         // 计算雨水量
 *         int water = 0;
 *         for (int i = 0; i < n; i++) {
 *             water += min(leftMax[i], rightMax[i]) - height[i];
 *         }
 *         
 *         return water;
 *     }
 * };
 * 
 * // 方法2：双指针（最优解，推荐）
 * class Solution {
 * public:
 *     int trap(vector<int>& height) {
 *         int n = height.size();
 *         if (n <= 2) return 0;
 *         
 *         int left = 0, right = n - 1;
 *         int leftMax = 0, rightMax = 0;
 *         int water = 0;
 *         
 *         while (left < right) {
 *             if (height[left] < height[right]) {
 *                 // 左边较矮，处理左边
 *                 if (height[left] >= leftMax) {
 *                     leftMax = height[left];
 *                 } else {
 *                     water += leftMax - height[left];
 *                 }
 *                 left++;
 *             } else {
 *                 // 右边较矮，处理右边
 *                 if (height[right] >= rightMax) {
 *                     rightMax = height[right];
 *                 } else {
 *                     water += rightMax - height[right];
 *                 }
 *                 right--;
 *             }
 *         }
 *         
 *         return water;
 *     }
 * };
 * 
 * // 方法3：单调栈
 * class Solution {
 * public:
 *     int trap(vector<int>& height) {
 *         stack<int> stk;
 *         int water = 0;
 *         
 *         for (int i = 0; i < height.size(); i++) {
 *             // 当前柱子比栈顶高，可以接雨水
 *             while (!stk.empty() && height[i] > height[stk.top()]) {
 *                 int top = stk.top();
 *                 stk.pop();
 *                 
 *                 if (stk.empty()) break;
 *                 
 *                 // 计算宽度和高度
 *                 int width = i - stk.top() - 1;
 *                 int h = min(height[i], height[stk.top()]) - height[top];
 *                 water += width * h;
 *             }
 *             stk.push(i);
 *         }
 *         
 *         return water;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 
 * 方法1（动态规划）：
 * - 时间复杂度：O(n) - 需要三次遍历
 * - 空间复杂度：O(n) - 需要两个辅助数组
 * 
 * 方法2（双指针）：
 * - 时间复杂度：O(n) - 只需一次遍历
 * - 空间复杂度：O(1) - 只需常数额外空间 ⭐⭐⭐
 * 
 * 方法3（单调栈）：
 * - 时间复杂度：O(n) - 每个元素最多入栈出栈一次
 * - 空间复杂度：O(n) - 栈的空间
 * 
 * 【关键点】
 * 
 * 1. **核心公式**：每个位置的雨水 = min(左边最高, 右边最高) - 当前高度
 * 
 * 2. **双指针为什么正确**：
 *    - 如果 height[left] < height[right]，说明右边一定有更高的柱子
 *    - 此时 left 位置的雨水只取决于 leftMax
 *    - 反之亦然
 * 
 * 3. **三种方法对比**：
 *    - 动态规划：最易理解，但需要额外空间
 *    - 双指针：最优解，O(1) 空间
 *    - 单调栈：按层计算，思路独特
 * 
 * 【图解示例】
 * height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 
 * 位置:  0 1 2 3 4 5 6 7 8 9 10 11
 * 高度:  0 1 0 2 1 0 1 3 2 1 2  1
 * 左最高:0 1 1 2 2 2 2 3 3 3 3  3
 * 右最高:3 3 3 3 3 3 3 3 2 2 2  1
 * 雨水:  0 0 1 0 1 2 1 0 0 1 0  0
 * 
 * 总雨水 = 6
 * 
 * 【面试高频程度】⭐⭐⭐⭐⭐
 * - 字节跳动：超高频！几乎必考
 * - 腾讯：高频
 * - 阿里：高频
 * - 美团：高频
 * 
 * 【相关题目】
 * - LeetCode 11: 盛最多水的容器（类似思想）
 * - LeetCode 84: 柱状图中最大的矩形（单调栈）
 * - LeetCode 407: 接雨水 II（3D 版本）
 * 
 * 【面试技巧】
 * 1. 先说动态规划解法（易理解）
 * 2. 再优化到双指针（展示优化能力）
 * 3. 如果面试官要求，可以补充单调栈解法
 */

