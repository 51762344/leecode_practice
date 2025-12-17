/*
 * 题目编号: 70
 * 题目名称: 爬楼梯
 * 难度: 简单
 * 
 * 题目描述:
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 示例 1:
 * 输入: n = 2
 * 输出: 2
 * 解释: 有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
 * 示例 2:
 * 输入: n = 3
 * 输出: 3
 * 解释: 有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 * 
 * 提示:
 * - 1 <= n <= 45
 */

/*
@Solution
class Solution {
public:
    int climbStairs(int n);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [70. 爬楼梯]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    RUN_TEST(solution.climbStairs(2), 2, "测试用例 1: n=2");
    
    // 测试用例 2
    RUN_TEST(solution.climbStairs(3), 3, "测试用例 2: n=3");
    
    // 测试用例 3
    RUN_TEST(solution.climbStairs(4), 5, "测试用例 3: n=4");
    
    // 测试用例 4
    RUN_TEST(solution.climbStairs(5), 8, "测试用例 4: n=5");
    
    // 测试用例 5
    RUN_TEST(solution.climbStairs(1), 1, "测试用例 5: n=1");
    
    // 测试用例 6：较大的数
    RUN_TEST(solution.climbStairs(10), 89, "测试用例 6: n=10");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 爬楼梯是经典的动态规划问题，也是斐波那契数列的应用。
 * 
 * 核心思路：
 * 到达第 n 阶有两种方式：
 * 1. 从第 n-1 阶爬1阶
 * 2. 从第 n-2 阶爬2阶
 * 因此：dp[n] = dp[n-1] + dp[n-2]
 * 
 * 【算法步骤】
 * 1. 定义状态：dp[i] 表示到达第 i 阶的方法数
 * 2. 初始状态：dp[1] = 1, dp[2] = 2
 * 3. 状态转移：dp[i] = dp[i-1] + dp[i-2]
 * 4. 返回 dp[n]
 * 
 * 【参考解法1：动态规划（数组）】
 * class Solution {
 * public:
 *     int climbStairs(int n) {
 *         if (n <= 2) return n;
 *         
 *         vector<int> dp(n + 1);
 *         dp[1] = 1;
 *         dp[2] = 2;
 *         
 *         for (int i = 3; i <= n; i++) {
 *             dp[i] = dp[i - 1] + dp[i - 2];
 *         }
 *         
 *         return dp[n];
 *     }
 * };
 * 
 * 【参考解法2：空间优化】
 * 由于只需要前两个状态，可以用两个变量代替数组。
 * 
 * class Solution {
 * public:
 *     int climbStairs(int n) {
 *         if (n <= 2) return n;
 *         
 *         int prev2 = 1; // dp[i-2]
 *         int prev1 = 2; // dp[i-1]
 *         
 *         for (int i = 3; i <= n; i++) {
 *             int current = prev1 + prev2;
 *             prev2 = prev1;
 *             prev1 = current;
 *         }
 *         
 *         return prev1;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n)
 * 空间复杂度：O(n) 数组版 / O(1) 优化版
 */
