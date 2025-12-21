/*
 * 题目编号: 72
 * 题目名称: 编辑距离
 * 难度: 困难
 * 
 * 题目描述:
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数。
 * 
 * 你可以对一个单词进行如下三种操作：
 * - 插入一个字符
 * - 删除一个字符
 * - 替换一个字符
 * 
 * 示例 1:
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释: 
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 示例 2:
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释: 
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 提示:
 * - 0 <= word1.length, word2.length <= 500
 * - word1 和 word2 由小写英文字母组成
 */

/*
@Solution
class Solution {
public:
    int minDistance(string word1, string word2);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [72. 编辑距离]..." << endl;
    
    // 测试用例 1
    string word11 = "horse", word12 = "ros";
    int expected1 = 3;
    int result1 = solution.minDistance(word11, word12);
    cout << "测试用例 1: word1=\"" << word11 << "\", word2=\"" << word12 << "\", 期望=" << expected1 << ", 实际=" << result1;
    if (result1 == expected1) {
        cout << " ✓ 通过" << endl;
    } else {
        cout << " ✗ 失败" << endl;
    }
    
    // 测试用例 2
    string word21 = "intention", word22 = "execution";
    int expected2 = 5;
    int result2 = solution.minDistance(word21, word22);
    cout << "测试用例 2: word1=\"" << word21 << "\", word2=\"" << word22 << "\", 期望=" << expected2 << ", 实际=" << result2;
    if (result2 == expected2) {
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
 * 这是一道经典的动态规划题目，需要计算将一个字符串转换成另一个字符串的最少编辑操作数。
 * 编辑操作包括：插入、删除、替换。
 * 
 * 核心思路：
 * 使用二维DP数组 dp[i][j] 表示 word1[0..i-1] 转换成 word2[0..j-1] 的最小操作数。
 * 状态转移方程：
 * - 如果 word1[i-1] == word2[j-1]，dp[i][j] = dp[i-1][j-1]
 * - 否则，dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
 * 边界条件：空字符串转换的代价。
 * 
 * 【算法步骤】
 * 1. 获取字符串长度 m = word1.size(), n = word2.size()
 * 2. 初始化DP数组 (m+1) x (n+1)
 * 3. 初始化边界：
 *    - dp[i][0] = i (删除操作)
 *    - dp[0][j] = j (插入操作)
 * 4. 填充DP数组：
 *    - 如果字符相等，dp[i][j] = dp[i-1][j-1]
 *    - 否则，dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
 * 5. 返回 dp[m][n]
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int minDistance(string word1, string word2) {
 *         int m = word1.size();
 *         int n = word2.size();
 *         
 *         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
 *         
 *         // 初始化边界
 *         for (int i = 0; i <= m; i++) {
 *             dp[i][0] = i;
 *         }
 *         for (int j = 0; j <= n; j++) {
 *             dp[0][j] = j;
 *         }
 *         
 *         // 填充DP数组
 *         for (int i = 1; i <= m; i++) {
 *             for (int j = 1; j <= n; j++) {
 *                 if (word1[i-1] == word2[j-1]) {
 *                     dp[i][j] = dp[i-1][j-1];
 *                 } else {
 *                     dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
 *                 }
 *             }
 *         }
 *         
 *         return dp[m][n];
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(m*n) - 需要遍历两个字符串的所有字符组合
 * 空间复杂度：O(m*n) - 使用了二维DP数组，可以优化为O(min(m,n))
 */