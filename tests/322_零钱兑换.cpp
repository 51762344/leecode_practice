/*
 * 题目编号: 322
 * 题目名称: 零钱兑换
 * 难度: 中等
 * 
 * 题目描述:
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 示例 1:
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 示例 3:
 * 输入: coins = [1], amount = 0
 * 输出: 0
 * 
 * 提示:
 * - 1 <= coins.length <= 12
 * - 1 <= coins[i] <= 2^31 - 1
 * - 0 <= amount <= 10^4
 */

/*
@Solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amount);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [322. 零钱兑换]..." << endl;
    
    // 测试用例 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    int expected1 = 3;
    int result1 = solution.coinChange(coins1, amount1);
    cout << "测试用例 1: coins=[1,2,5], amount=" << amount1 << ", 期望=" << expected1 << ", 实际=" << result1;
    if (result1 == expected1) {
        cout << " ✓ 通过" << endl;
    } else {
        cout << " ✗ 失败" << endl;
    }
    
    // 测试用例 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    int expected2 = -1;
    int result2 = solution.coinChange(coins2, amount2);
    cout << "测试用例 2: coins=[2], amount=" << amount2 << ", 期望=" << expected2 << ", 实际=" << result2;
    if (result2 == expected2) {
        cout << " ✓ 通过" << endl;
    } else {
        cout << " ✗ 失败" << endl;
    }
    
    // 测试用例 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    int expected3 = 0;
    int result3 = solution.coinChange(coins3, amount3);
    cout << "测试用例 3: coins=[1], amount=" << amount3 << ", 期望=" << expected3 << ", 实际=" << result3;
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
 * 这是一道经典的动态规划题目，需要找到凑成指定金额的最少硬币数。每个硬币可以无限使用。
 * 
 * 核心思路：
 * 使用一维DP数组 dp[i] 表示凑成金额 i 所需的最少硬币数。
 * 状态转移方程：dp[i] = min(dp[i], dp[i - coin] + 1) 对于每个硬币 coin
 * 边界条件：dp[0] = 0，无法凑成的金额设为特殊值。
 * 
 * 【算法步骤】
 * 1. 初始化DP数组，大小为 amount + 1，初始值设为 amount + 1（表示无法凑成）
 * 2. dp[0] = 0
 * 3. 遍历每个金额 i 从 1 到 amount：
 *    - 对于每个硬币 coin，如果 i >= coin：
 *      - dp[i] = min(dp[i], dp[i - coin] + 1)
 * 4. 如果 dp[amount] == amount + 1，返回 -1，否则返回 dp[amount]
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int coinChange(vector<int>& coins, int amount) {
 *         vector<int> dp(amount + 1, amount + 1);
 *         dp[0] = 0;
 *         
 *         for (int i = 1; i <= amount; i++) {
 *             for (int coin : coins) {
 *                 if (i >= coin) {
 *                     dp[i] = min(dp[i], dp[i - coin] + 1);
 *                 }
 *             }
 *         }
 *         
 *         return dp[amount] == amount + 1 ? -1 : dp[amount];
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(amount * len(coins)) - 对于每个金额，遍历所有硬币
 * 空间复杂度：O(amount) - 使用了一维DP数组
 */