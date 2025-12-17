/*
 * 题目编号: 121
 * 题目名称: 买卖股票的最佳时机
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个数组 prices，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。
 * 设计一个算法来计算你所能获取的最大利润。
 * 
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0。
 * 
 * 示例 1:
 * 输入: prices = [7,1,5,3,6,4]
 * 输出: 5
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，
 *      最大利润 = 6-1 = 5。
 *      注意利润不能是 7-1 = 6，因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 * 
 * 示例 2:
 * 输入: prices = [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下，没有交易完成，所以最大利润为 0。
 * 
 * 提示:
 * - 1 <= prices.length <= 10^5
 * - 0 <= prices[i] <= 10^4
 */

/*
@Solution
class Solution {
public:
    int maxProfit(vector<int>& prices);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [121. 买卖股票的最佳时机]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    RUN_TEST(solution.maxProfit(prices1), 5, 
             "测试用例 1: [7,1,5,3,6,4]");
    
    // 测试用例 2：价格一直下跌
    vector<int> prices2 = {7, 6, 4, 3, 1};
    RUN_TEST(solution.maxProfit(prices2), 0, 
             "测试用例 2: [7,6,4,3,1]");
    
    // 测试用例 3：只有一天
    vector<int> prices3 = {5};
    RUN_TEST(solution.maxProfit(prices3), 0, 
             "测试用例 3: [5]");
    
    // 测试用例 4：价格一直上涨
    vector<int> prices4 = {1, 2, 3, 4, 5};
    RUN_TEST(solution.maxProfit(prices4), 4, 
             "测试用例 4: [1,2,3,4,5]");
    
    // 测试用例 5：先跌后涨
    vector<int> prices5 = {3, 2, 6, 5, 0, 3};
    RUN_TEST(solution.maxProfit(prices5), 4, 
             "测试用例 5: [3,2,6,5,0,3]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 买卖股票的最佳时机，要求只能买卖一次，求最大利润。
 * 
 * 核心思路：
 * 遍历价格数组，维护两个变量：
 * 1. minPrice: 到目前为止遇到的最低价格
 * 2. maxProfit: 到目前为止能获得的最大利润
 * 
 * 对于每一天的价格，考虑在这一天卖出能获得的利润。
 * 
 * 【算法步骤】
 * 1. 初始化 minPrice = INT_MAX, maxProfit = 0
 * 2. 遍历价格数组：
 *    - 更新 minPrice = min(minPrice, prices[i])
 *    - 计算当天卖出的利润：prices[i] - minPrice
 *    - 更新 maxProfit = max(maxProfit, 当天利润)
 * 3. 返回 maxProfit
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int maxProfit(vector<int>& prices) {
 *         if (prices.empty()) return 0;
 *         
 *         int minPrice = INT_MAX;  // 历史最低价格
 *         int maxProfit = 0;       // 最大利润
 *         
 *         for (int price : prices) {
 *             // 更新历史最低价格
 *             minPrice = min(minPrice, price);
 *             
 *             // 计算今天卖出的利润
 *             int profit = price - minPrice;
 *             
 *             // 更新最大利润
 *             maxProfit = max(maxProfit, profit);
 *         }
 *         
 *         return maxProfit;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n) - 只需遍历一次数组
 * 空间复杂度：O(1) - 只使用常量空间
 */
