/*
 * 题目编号: 200
 * 题目名称: 岛屿数量
 * 难度: 中等
 *
 * 题目描述:
 * 给你一个由 '1'（陆地）和 '0'（水）组成的二维网格 grid，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 你可以假设网格的四个边均被水包围。
 */

/*
@Solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

static vector<vector<char>> toGrid(const vector<string>& rows) {
    vector<vector<char>> g;
    g.reserve(rows.size());
    for (const auto& r : rows) {
        g.emplace_back(r.begin(), r.end());
    }
    return g;
}

int main() {
    Solution solution;

    cout << "开始测试 [200. 岛屿数量]..." << endl;
    cout << string(50, '-') << endl;

    {
        auto grid = toGrid({
            "11110",
            "11010",
            "11000",
            "00000",
        });
        RUN_TEST(solution.numIslands(grid), 1, "测试用例 1: 1座岛");
    }

    {
        auto grid = toGrid({
            "11000",
            "11000",
            "00100",
            "00011",
        });
        RUN_TEST(solution.numIslands(grid), 3, "测试用例 2: 3座岛");
    }

    {
        auto grid = toGrid({});
        RUN_TEST(solution.numIslands(grid), 0, "测试用例 3: 空网格");
    }

    {
        auto grid = toGrid({"0"});
        RUN_TEST(solution.numIslands(grid), 0, "测试用例 4: 单点水");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】DFS/BFS 把每个岛屿“淹掉”
 * 遍历网格，遇到一个 '1' 就说明发现新岛屿，答案 +1。
 * 然后从该点出发做 DFS/BFS，把与它连通的所有 '1' 都改成 '0'（或标记 visited），避免重复计数。
 *
 * 【参考解法】（DFS）
 * class Solution {
 * public:
 *     int numIslands(vector<vector<char>>& grid) {
 *         int m = (int)grid.size();
 *         if (m == 0) return 0;
 *         int n = (int)grid[0].size();
 *         int ans = 0;
 *         for (int i = 0; i < m; i++) {
 *             for (int j = 0; j < n; j++) {
 *                 if (grid[i][j] == '1') {
 *                     ans++;
 *                     dfs(grid, i, j);
 *                 }
 *             }
 *         }
 *         return ans;
 *     }
 * private:
 *     void dfs(vector<vector<char>>& g, int i, int j) {
 *         int m = (int)g.size(), n = (int)g[0].size();
 *         if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != '1') return;
 *         g[i][j] = '0';
 *         dfs(g, i + 1, j);
 *         dfs(g, i - 1, j);
 *         dfs(g, i, j + 1);
 *         dfs(g, i, j - 1);
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(m*n)（每个格子最多访问一次）
 * - 空间：O(m*n) 最坏（递归栈），若用 BFS 队列也可能到 O(m*n)
 */
