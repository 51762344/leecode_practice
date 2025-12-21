/*
 * 题目编号: 64
 * 题目名称: 最小路径和
 * 难度: 中等
 * 
 * 题目描述:
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，
 * 使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例 1:
 * 输入: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 示例 2:
 * 输入: grid = [[1,2,3],[4,5,6]]
 * 输出: 12
 * 
 * 提示:
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 200
 * - 0 <= grid[i][j] <= 100
 */

/*
@Solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [64. 最小路径和]..." << endl;
    
    // 测试用例 1
    vector<vector<int>> grid1 = {{1,3,1},{1,5,1},{4,2,1}};
    int expected1 = 7;
    int result1 = solution.minPathSum(grid1);
    cout << "测试用例 1: 期望=" << expected1 << ", 实际=" << result1;
    if (result1 == expected1) {
        cout << " ✓ 通过" << endl;
    } else {
        cout << " ✗ 失败" << endl;
    }
    
    // 测试用例 2
    vector<vector<int>> grid2 = {{1,2,3},{4,5,6}};
    int expected2 = 12;
    int result2 = solution.minPathSum(grid2);
    cout << "测试用例 2: 期望=" << expected2 << ", 实际=" << result2;
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
 * 这是一道经典的动态规划题目。机器人只能向下或向右移动，我们需要找到从左上角到右下角的最小路径和。
 * 
 * 核心思路：
 * 使用二维DP数组 dp[i][j] 表示到达位置 (i,j) 的最小路径和。
 * 状态转移方程：dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
 * 边界条件：第一行只能从左边来，第一列只能从上边来。
 * 
 * 【算法步骤】
 * 1. 如果网格为空，返回0
 * 2. 初始化DP数组，大小与网格相同
 * 3. 初始化第一行：dp[0][j] = dp[0][j-1] + grid[0][j]
 * 4. 初始化第一列：dp[i][0] = dp[i-1][0] + grid[i][0]
 * 5. 填充其他位置：dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
 * 6. 返回 dp[m-1][n-1]
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int minPathSum(vector<vector<int>>& grid) {
 *         if (grid.empty() || grid[0].empty()) return 0;
 *         
 *         int m = grid.size();
 *         int n = grid[0].size();
 *         
 *         vector<vector<int>> dp(m, vector<int>(n, 0));
 *         
 *         // 初始化起点
 *         dp[0][0] = grid[0][0];
 *         
 *         // 初始化第一行
 *         for (int j = 1; j < n; j++) {
 *             dp[0][j] = dp[0][j-1] + grid[0][j];
 *         }
 *         
 *         // 初始化第一列
 *         for (int i = 1; i < m; i++) {
 *             dp[i][0] = dp[i-1][0] + grid[i][0];
 *         }
 *         
 *         // 填充其他位置
 *         for (int i = 1; i < m; i++) {
 *             for (int j = 1; j < n; j++) {
 *                 dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
 *             }
 *         }
 *         
 *         return dp[m-1][n-1];
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(m*n) - 需要遍历整个网格
 * 空间复杂度：O(m*n) - 使用了二维DP数组，可以优化为一维数组节省空间
 */