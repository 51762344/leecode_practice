/*
 * 题目编号: 239
 * 题目名称: 滑动窗口最大值
 * 难度: 困难
 *
 * 题目描述:
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
 * 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 * 返回 滑动窗口中的最大值。
 */

/*
@Solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

int main() {
    Solution solution;

    cout << "开始测试 [239. 滑动窗口最大值]..." << endl;
    cout << string(50, '-') << endl;

    {
        vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        vector<int> expected = {3, 3, 5, 5, 6, 7};
        RUN_TEST(solution.maxSlidingWindow(nums, 3), expected,
                 "测试用例 1: [1,3,-1,-3,5,3,6,7], k=3");
    }

    {
        vector<int> nums = {1};
        vector<int> expected = {1};
        RUN_TEST(solution.maxSlidingWindow(nums, 1), expected,
                 "测试用例 2: [1], k=1");
    }

    {
        vector<int> nums = {9, 11};
        vector<int> expected = {11};
        RUN_TEST(solution.maxSlidingWindow(nums, 2), expected,
                 "测试用例 3: [9,11], k=2");
    }

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心思路】单调队列（双端队列维护候选最大值下标）
 * 维护一个下标 deque，保证对应的 nums 值单调递减：
 * - 新元素进窗口时：把队尾所有 <= 新元素的下标弹掉（它们不可能再成为最大值）。
 * - 再把新下标压入队尾。
 * - 窗口左端移动时：如果队首下标已经滑出窗口（<= i-k），弹出队首。
 * - 当 i >= k-1 时，队首就是当前窗口最大值。
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
 *         deque<int> dq; // 存下标，nums[dq] 递减
 *         vector<int> ans;
 *         for (int i = 0; i < (int)nums.size(); i++) {
 *             while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
 *             while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
 *             dq.push_back(i);
 *             if (i >= k - 1) ans.push_back(nums[dq.front()]);
 *         }
 *         return ans;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n)（每个元素最多入队出队一次）
 * - 空间：O(k)
 */
