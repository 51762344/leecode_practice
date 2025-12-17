/*
 * 题目编号: 56
 * 题目名称: 合并区间
 * 难度: 中等
 *
 * 题目描述:
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]。
 * 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 */

/*
@Solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

static vector<vector<int>> normalize2d(vector<vector<int>> v) {
    sort(v.begin(), v.end());
    return v;
}

int main() {
    Solution solution;

    cout << "开始测试 [56. 合并区间]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        vector<vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
        RUN_TEST(normalize2d(solution.merge(intervals)), normalize2d(expected),
                 "测试用例 1: [[1,3],[2,6],[8,10],[15,18]]");
    }

    {
        vector<vector<int>> intervals = {{1, 4}, {4, 5}};
        vector<vector<int>> expected = {{1, 5}};
        RUN_TEST(normalize2d(solution.merge(intervals)), normalize2d(expected),
                 "测试用例 2: [[1,4],[4,5]]");
    }

    {
        vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
        vector<vector<int>> expected = {{0, 5}};
        RUN_TEST(normalize2d(solution.merge(intervals)), normalize2d(expected),
                 "测试用例 3: [[1,4],[0,2],[3,5]]");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】排序后线性合并
 * 1) 按区间起点升序排序（起点相同按终点升序也可）。
 * 2) 用结果数组维护当前合并到的最后一个区间：
 *    - 若新区间 start <= last.end，则更新 last.end = max(last.end, end)；
 *    - 否则直接追加新区间。
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     vector<vector<int>> merge(vector<vector<int>>& intervals) {
 *         sort(intervals.begin(), intervals.end(),
 *              [](const auto& a, const auto& b) {
 *                  if (a[0] != b[0]) return a[0] < b[0];
 *                  return a[1] < b[1];
 *              });
 *         vector<vector<int>> ans;
 *         for (const auto& it : intervals) {
 *             if (ans.empty() || it[0] > ans.back()[1]) {
 *                 ans.push_back(it);
 *             } else {
 *                 ans.back()[1] = max(ans.back()[1], it[1]);
 *             }
 *         }
 *         return ans;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n log n)
 * - 空间：O(1)~O(log n)（排序栈空间），不计输出
 */
