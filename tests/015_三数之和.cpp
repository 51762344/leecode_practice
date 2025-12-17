/*
 * 题目编号: 15
 * 题目名称: 三数之和
 * 难度: 中等
 *
 * 题目描述:
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足
 * i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0。
 * 请你返回所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 */

/*
@Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

static vector<vector<int>> normalize(vector<vector<int>> v) {
    for (auto& t : v) {
        sort(t.begin(), t.end());
    }
    sort(v.begin(), v.end());
    return v;
}

int main() {
    Solution solution;

    cout << "开始测试 [15. 三数之和]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
        RUN_TEST(normalize(solution.threeSum(nums)), normalize(expected),
                 "测试用例 1: [-1,0,1,2,-1,-4]");
    }

    {
        vector<int> nums = {0, 1, 1};
        vector<vector<int>> expected = {};
        RUN_TEST(normalize(solution.threeSum(nums)), normalize(expected),
                 "测试用例 2: [0,1,1]");
    }

    {
        vector<int> nums = {0, 0, 0};
        vector<vector<int>> expected = {{0, 0, 0}};
        RUN_TEST(normalize(solution.threeSum(nums)), normalize(expected),
                 "测试用例 3: [0,0,0]");
    }

    {
        vector<int> nums = {-2, 0, 1, 1, 2};
        vector<vector<int>> expected = {{-2, 0, 2}, {-2, 1, 1}};
        RUN_TEST(normalize(solution.threeSum(nums)), normalize(expected),
                 "测试用例 4: [-2,0,1,1,2]");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】排序 + 双指针
 * 1) 先将 nums 排序。
 * 2) 枚举第一个数 nums[i]，把问题转为在区间 (i+1..n-1) 内找两数之和为 -nums[i]。
 * 3) 用双指针 l/r 线性扫描；每次命中后跳过重复值，避免重复三元组。
 *
 * 【关键点】
 * - i 也要跳过重复（nums[i] == nums[i-1] 时 continue）。
 * - nums[i] > 0 可直接 break（因为已排序，后面都 >= nums[i]）。
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     vector<vector<int>> threeSum(vector<int>& nums) {
 *         sort(nums.begin(), nums.end());
 *         vector<vector<int>> ans;
 *         const int n = (int)nums.size();
 *         for (int i = 0; i < n; i++) {
 *             if (i > 0 && nums[i] == nums[i - 1]) continue;
 *             if (nums[i] > 0) break;
 *             int l = i + 1, r = n - 1;
 *             while (l < r) {
 *                 long long s = 1LL * nums[i] + nums[l] + nums[r];
 *                 if (s < 0) {
 *                     l++;
 *                 } else if (s > 0) {
 *                     r--;
 *                 } else {
 *                     ans.push_back({nums[i], nums[l], nums[r]});
 *                     int lv = nums[l], rv = nums[r];
 *                     while (l < r && nums[l] == lv) l++;
 *                     while (l < r && nums[r] == rv) r--;
 *                 }
 *             }
 *         }
 *         return ans;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n^2)（排序 O(n log n) + 枚举 i 与双指针 O(n^2)）
 * - 空间：O(1)~O(log n)（取决于排序实现的栈空间），不计输出
 */
