/*
 * 题目编号: 994
 * 题目名称: 腐烂的橘子
 * 难度: 中等
 *
 * 题目描述:
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 * 0 代表空单元格；1 代表新鲜橘子；2 代表腐烂橘子。
 * 每分钟，腐烂橘子周围（上下左右）4 个方向相邻的新鲜橘子都会腐烂。
 * 返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。
 * 如果不可能，返回 -1。
 */

/*
@Solution
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

int main() {
    Solution solution;

    cout << "开始测试 [994. 腐烂的橘子]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<vector<int>> grid = {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1},
        };
        RUN_TEST(solution.orangesRotting(grid), 4, "测试用例 1");
    }

    {
        vector<vector<int>> grid = {
            {2, 1, 1},
            {0, 1, 1},
            {1, 0, 1},
        };
        RUN_TEST(solution.orangesRotting(grid), -1, "测试用例 2: 不可能" );
    }

    {
        vector<vector<int>> grid = {
            {0, 2},
        };
        RUN_TEST(solution.orangesRotting(grid), 0, "测试用例 3: 没有新鲜橘子");
    }

    {
        vector<vector<int>> grid = {
            {1},
        };
        RUN_TEST(solution.orangesRotting(grid), -1, "测试用例 4: 只有新鲜橘子" );
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】多源 BFS（层序扩散分钟数）
 * 把所有腐烂橘子(2)作为 BFS 初始队列（多源），同时统计新鲜橘子数量 fresh。
 * 每一层 BFS 代表“过了 1 分钟”：腐烂橘子向四周扩散，把相邻新鲜橘子变成腐烂并入队，fresh--。
 * BFS 结束后：
 * - 若 fresh > 0，说明还有新鲜橘子无法被感染，返回 -1
 * - 否则返回扩散的分钟数（注意：如果一开始 fresh==0，则答案为 0）
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     int orangesRotting(vector<vector<int>>& grid) {
 *         int m = (int)grid.size();
 *         if (m == 0) return 0;
 *         int n = (int)grid[0].size();
 *         queue<pair<int,int>> q;
 *         int fresh = 0;
 *         for (int i = 0; i < m; i++) {
 *             for (int j = 0; j < n; j++) {
 *                 if (grid[i][j] == 2) q.push({i, j});
 *                 else if (grid[i][j] == 1) fresh++;
 *             }
 *         }
 *         if (fresh == 0) return 0;
 *         int minutes = -1;
 *         const int dx[4] = {1, -1, 0, 0};
 *         const int dy[4] = {0, 0, 1, -1};
 *         while (!q.empty()) {
 *             int sz = (int)q.size();
 *             minutes++;
 *             for (int t = 0; t < sz; t++) {
 *                 auto [x, y] = q.front(); q.pop();
 *                 for (int d = 0; d < 4; d++) {
 *                     int nx = x + dx[d], ny = y + dy[d];
 *                     if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
 *                     if (grid[nx][ny] != 1) continue;
 *                     grid[nx][ny] = 2;
 *                     fresh--;
 *                     q.push({nx, ny});
 *                 }
 *             }
 *         }
 *         return fresh == 0 ? minutes : -1;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(m*n)
 * - 空间：O(m*n)（队列最坏情况）
 */
