/*
 * 题目编号: 46
 * 题目名称: 全排列
 * 难度: 中等
 *
 * 题目描述:
 * 给定一个不含重复数字的数组 nums ，返回其所有可能的全排列。
 * 你可以按任意顺序返回答案。
 */

/*
@Solution
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums);
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

    cout << "开始测试 [46. 全排列]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> expected = {
            {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1},
        };
        RUN_TEST(normalize2d(solution.permute(nums)), normalize2d(expected),
                 "测试用例 1: [1,2,3]");
    }

    {
        vector<int> nums = {0, 1};
        vector<vector<int>> expected = {{0, 1}, {1, 0}};
        RUN_TEST(normalize2d(solution.permute(nums)), normalize2d(expected),
                 "测试用例 2: [0,1]");
    }

    {
        vector<int> nums = {1};
        vector<vector<int>> expected = {{1}};
        RUN_TEST(normalize2d(solution.permute(nums)), normalize2d(expected),
                 "测试用例 3: [1]");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】回溯（DFS）+ 标记使用
 * 用路径 path 记录当前排列，used[i] 表示 nums[i] 是否已选。
 * 每一层选择一个未使用元素加入 path，递归到长度为 n 时收集答案。
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     vector<vector<int>> permute(vector<int>& nums) {
 *         vector<vector<int>> ans;
 *         vector<int> path;
 *         vector<int> used(nums.size(), 0);
 *         dfs(nums, used, path, ans);
 *         return ans;
 *     }
 * private:
 *     void dfs(const vector<int>& nums, vector<int>& used, vector<int>& path,
 *              vector<vector<int>>& ans) {
 *         if (path.size() == nums.size()) {
 *             ans.push_back(path);
 *             return;
 *         }
 *         for (size_t i = 0; i < nums.size(); i++) {
 *             if (used[i]) continue;
 *             used[i] = 1;
 *             path.push_back(nums[i]);
 *             dfs(nums, used, path, ans);
 *             path.pop_back();
 *             used[i] = 0;
 *         }
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n * n!)（生成 n! 个排列，每个长度 n）
 * - 空间：O(n)（递归栈 + path + used），不计输出
 */
