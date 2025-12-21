/*
 * 题目编号: 62
 * 题目名称: 不同路径
 * 难度: 中等
 * 
 * 题目描述:
 * 一个机器人位于一个 m x n 网格的左上角，机器人每次只能向下或者向右移动一步。
 * 机器人试图达到网格的右下角。问总共有多少条不同的路径？
 * 
 * 示例 1:
 * 输入: m = 3, n = 7
 * 输出: 28
 * 
 * 示例 2:
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释: 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 * 
 * 示例 3:
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 示例 4:
 * 输入: m = 3, n = 3
 * 输出: 6
 * 
 * 提示:
 * - 1 <= m, n <= 100
 * - 题目数据保证答案小于等于 2 * 10^9
 */

/*
@Solution
class Solution {
public:
    int uniquePaths(int m, int n);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [62. 不同路径]..." << endl;
    
    // 测试用例 1
    int m1 = 3, n1 = 7;
    int expected1 = 28;
    int result1 = solution.uniquePaths(m1, n1);
    cout << "测试用例 1: m=" << m1 << ", n=" << n1 << ", 期望=" << expected1 << ", 实际=" << result1;
    if (result1 == expected1) {
        cout << " ✓ 通过" << endl;
    } else {
        cout << " ✗ 失败" << endl;
    }
    
    // 测试用例 2
    int m2 = 3, n2 = 2;
    int expected2 = 3;
    int result2 = solution.uniquePaths(m2, n2);
    cout << "测试用例 2: m=" << m2 << ", n=" << n2 << ", 期望=" << expected2 << ", 实际=" << result2;
    if (result2 == expected2) {
        cout << " ✓ 通过" << endl;
    } else {
        cout << " ✗ 失败" << endl;
    }
    
    // 测试用例 3
    int m3 = 1, n3 = 1;
    int expected3 = 1;
    int result3 = solution.uniquePaths(m3, n3);
    cout << "测试用例 3: m=" << m3 << ", n=" << n3 << ", 期望=" << expected3 << ", 实际=" << result3;
    if (result3 == expected3) {
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
 * 这是一道经典的动态规划题目。机器人只能向下或向右移动，我们需要计算从左上角到右下角的路径总数。
 * 
 * 核心思路：
 * 使用二维DP数组 dp[i][j] 表示到达位置 (i,j) 的路径数。
 * 状态转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 边界条件：第一行和第一列都是1，因为只能向右或向下移动。
 * 
 * 【算法步骤】
 * 1. 如果m或n为1，返回1（边界情况）
 * 2. 初始化DP数组，大小 m x n
 * 3. 初始化第一行：dp[0][j] = 1
 * 4. 初始化第一列：dp[i][0] = 1
 * 5. 填充其他位置：dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 6. 返回 dp[m-1][n-1]
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int uniquePaths(int m, int n) {
 *         if (m <= 0 || n <= 0) return 0;
 *         if (m == 1 || n == 1) return 1;
 *         
 *         vector<vector<int>> dp(m, vector<int>(n, 1));
 *         
 *         for (int i = 1; i < m; i++) {
 *             for (int j = 1; j < n; j++) {
 *                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
 *             }
 *         }
 *         
 *         return dp[m-1][n-1];
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(m*n) - 需要填充整个DP数组
 * 空间复杂度：O(m*n) - 使用了二维DP数组，可以优化为一维数组
 */