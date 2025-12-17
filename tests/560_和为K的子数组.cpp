/*
 * 题目编号: 560
 * 题目名称: 和为 K 的子数组
 * 难度: 中等
 *
 * 题目描述:
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。
 */

/*
@Solution
class Solution {
public:
    int subarraySum(vector<int>& nums, int k);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

int main() {
    Solution solution;

    cout << "开始测试 [560. 和为K的子数组]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<int> nums = {1, 1, 1};
        RUN_TEST(solution.subarraySum(nums, 2), 2, "测试用例 1: [1,1,1], k=2");
    }

    {
        vector<int> nums = {1, 2, 3};
        RUN_TEST(solution.subarraySum(nums, 3), 2, "测试用例 2: [1,2,3], k=3");
    }

    {
        vector<int> nums = {1, -1, 0};
        RUN_TEST(solution.subarraySum(nums, 0), 3, "测试用例 3: [1,-1,0], k=0");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】前缀和 + 哈希表计数
 * 令 prefix[i] 为 nums[0..i] 的前缀和。若存在子数组 (l..r) 和为 k：
 *   prefix[r] - prefix[l-1] = k  =>  prefix[l-1] = prefix[r] - k
 * 所以遍历 r 时，只要知道此前出现过多少次 prefix[r]-k，就能累加答案。
 * 用 unordered_map<sum, count> 维护“某个前缀和出现次数”，并初始化 mp[0]=1（空前缀）。
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     int subarraySum(vector<int>& nums, int k) {
 *         unordered_map<int, int> cnt;
 *         cnt[0] = 1;
 *         int sum = 0;
 *         int ans = 0;
 *         for (int x : nums) {
 *             sum += x;
 *             auto it = cnt.find(sum - k);
 *             if (it != cnt.end()) ans += it->second;
 *             cnt[sum]++;
 *         }
 *         return ans;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n)
 * - 空间：O(n)
 */
