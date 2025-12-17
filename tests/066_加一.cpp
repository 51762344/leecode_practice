/*
 * 题目编号: 66
 * 题目名称: 加一
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位，数组中每个元素只存储单个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 输入: digits = [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123
 * 
 * 示例 2:
 * 输入: digits = [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321
 * 
 * 示例 3:
 * 输入: digits = [9]
 * 输出: [1,0]
 * 解释: 输入数组表示数字 9
 * 
 * 示例 4:
 * 输入: digits = [9,9,9]
 * 输出: [1,0,0,0]
 * 
 * 提示:
 * - 1 <= digits.length <= 100
 * - 0 <= digits[i] <= 9
 */

/*
@Solution
class Solution {
public:
    vector<int> plusOne(vector<int>& digits);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [66. 加一]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<int> digits1 = {1, 2, 3};
    RUN_TEST(solution.plusOne(digits1), vector<int>({1, 2, 4}), 
             "测试用例 1: [1,2,3]");
    
    // 测试用例 2
    vector<int> digits2 = {4, 3, 2, 1};
    RUN_TEST(solution.plusOne(digits2), vector<int>({4, 3, 2, 2}), 
             "测试用例 2: [4,3,2,1]");
    
    // 测试用例 3
    vector<int> digits3 = {9};
    RUN_TEST(solution.plusOne(digits3), vector<int>({1, 0}), 
             "测试用例 3: [9]");
    
    // 测试用例 4
    vector<int> digits4 = {9, 9, 9};
    RUN_TEST(solution.plusOne(digits4), vector<int>({1, 0, 0, 0}), 
             "测试用例 4: [9,9,9]");
    
    // 测试用例 5
    vector<int> digits5 = {1, 9, 9};
    RUN_TEST(solution.plusOne(digits5), vector<int>({2, 0, 0}), 
             "测试用例 5: [1,9,9]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 给数组表示的整数加一，需要处理进位问题。从数组末尾开始处理，模拟加法运算。
 * 
 * 核心思路：
 * 1. 从数组末尾开始，给最后一位加1
 * 2. 如果产生进位，继续向前处理
 * 3. 特殊情况：999...9 + 1 = 1000...0，需要在数组开头插入1
 * 
 * 【算法步骤】
 * 1. 从数组末尾开始遍历：
 *    - 如果当前位 < 9，直接加1并返回（不需要进位）
 *    - 如果当前位 = 9，设为0，继续处理前一位（需要进位）
 * 2. 如果遍历完成还有进位（全是9的情况）：
 *    - 在数组开头插入1，或创建新数组 [1, 0, 0, ..., 0]
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     vector<int> plusOne(vector<int>& digits) {
 *         int n = digits.size();
 *         
 *         // 从后向前遍历
 *         for (int i = n - 1; i >= 0; i--) {
 *             if (digits[i] < 9) {
 *                 // 不需要进位，直接加1返回
 *                 digits[i]++;
 *                 return digits;
 *             }
 *             // 需要进位，当前位变为0
 *             digits[i] = 0;
 *         }
 *         
 *         // 如果执行到这里，说明原数组全是9，需要进位到最高位
 *         // 例如 999 -> 1000
 *         vector<int> result(n + 1, 0);
 *         result[0] = 1;
 *         return result;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n) - 最坏情况需要遍历整个数组
 * 空间复杂度：O(1) 或 O(n) - 不需要进位时为 O(1)，全是9时需要新数组 O(n)
 */