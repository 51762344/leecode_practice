/*
 * 题目编号: 349
 * 题目名称: 两个数组的交集
 * 难度: 简单
 *
 * 题目描述:
 * 给定两个数组 nums1 和 nums2 ，返回它们的交集。
 * 输出结果中的每个元素一定是唯一的。可以不考虑输出结果的顺序。
 *
 * 示例 1:
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 *
 * 示例 2:
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4] 或 [4,9]
 */

/*
@Solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

static vector<int> sortVec(vector<int> v) {
    sort(v.begin(), v.end());
    return v;
}

int main() {
    Solution solution;

    cout << "开始测试 [349. 两个数组的交集]..." << endl;
    cout << string(50, '-') << endl;

    vector<int> a1 = {1, 2, 2, 1};
    vector<int> b1 = {2, 2};
    RUN_TEST(sortVec(solution.intersection(a1, b1)), vector<int>({2}), "测试用例 1: [1,2,2,1] & [2,2]");

    vector<int> a2 = {4, 9, 5};
    vector<int> b2 = {9, 4, 9, 8, 4};
    RUN_TEST(sortVec(solution.intersection(a2, b2)), vector<int>({4, 9}), "测试用例 2: [4,9,5] & [9,4,9,8,4]");

    vector<int> a3 = {1, 1, 1};
    vector<int> b3 = {1};
    RUN_TEST(sortVec(solution.intersection(a3, b3)), vector<int>({1}), "测试用例 3: 全重复");

    vector<int> a4 = {1, 2, 3};
    vector<int> b4 = {4, 5, 6};
    RUN_TEST(sortVec(solution.intersection(a4, b4)), vector<int>({}), "测试用例 4: 无交集");

    vector<int> a5 = {};
    vector<int> b5 = {1, 2};
    RUN_TEST(sortVec(solution.intersection(a5, b5)), vector<int>({}), "测试用例 5: 空数组");

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】哈希集合去重 + 查找（unordered_set::find）
 * 1) 把 nums1 放入 set1（自动去重）
 * 2) 遍历 nums2：
 *    - 如果 set1 里存在该元素（find != end），就放入 ansSet（再次去重）
 * 3) 把 ansSet 转成 vector 返回
 *
 * 【常用点】
 * - unordered_set<int> s(nums.begin(), nums.end())
 * - s.find(x) != s.end()
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
 *         unordered_set<int> set1(nums1.begin(), nums1.end());
 *         unordered_set<int> ans;
 *         for (int x : nums2) {
 *             if (set1.find(x) != set1.end()) {
 *                 ans.insert(x);
 *             }
 *         }
 *         return vector<int>(ans.begin(), ans.end());
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：平均 O(n + m)
 * - 空间：O(n)
 */

