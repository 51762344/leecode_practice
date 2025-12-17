/*
 * 题目编号: 13
 * 题目名称: 罗马数字转整数
 * 难度: 简单
 * 
 * 题目描述:
 * 罗马数字包含以下七种字符: I, V, X, L, C, D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如，罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。
 * 27 写做 XXVII, 即为 XX + V + II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特殊情况，例如 4 不写做 IIII，
 * 而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4。
 * 同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * - I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * - X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 * - C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 给定一个罗马数字，将其转换成整数。
 * 
 * 示例 1:
 * 输入: s = "III"
 * 输出: 3
 * 
 * 示例 2:
 * 输入: s = "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 输入: s = "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 输入: s = "LVIII"
 * 输出: 58
 * 解释: L = 50, V= 5, III = 3
 * 
 * 示例 5:
 * 输入: s = "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4
 * 
 * 提示:
 * - 1 <= s.length <= 15
 * - s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
 * - 题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
 */

/*
@Solution
class Solution {
public:
    int romanToInt(string s);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [13. 罗马数字转整数]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    RUN_TEST(solution.romanToInt("III"), 3, "测试用例 1: III");
    
    // 测试用例 2
    RUN_TEST(solution.romanToInt("IV"), 4, "测试用例 2: IV");
    
    // 测试用例 3
    RUN_TEST(solution.romanToInt("IX"), 9, "测试用例 3: IX");
    
    // 测试用例 4
    RUN_TEST(solution.romanToInt("LVIII"), 58, "测试用例 4: LVIII");
    
    // 测试用例 5
    RUN_TEST(solution.romanToInt("MCMXCIV"), 1994, "测试用例 5: MCMXCIV");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 罗马数字转整数的关键在于理解罗马数字的规则：
 * - 通常情况下，小的数字在大的数字右边表示加法（如 VI = 6）
 * - 特殊情况：小的数字在大的数字左边表示减法（如 IV = 4）
 * 
 * 核心思路：
 * 从左到右遍历字符串，如果当前字符代表的值小于右边的值，就减去当前值；否则加上当前值。
 * 
 * 【算法步骤】
 * 1. 建立罗马字符到数值的映射表
 * 2. 遍历字符串：
 *    - 如果当前字符的值 < 下一个字符的值，则减去当前值
 *    - 否则加上当前值
 * 3. 返回累加结果
 * 
 * 【参考解法】
 * class Solution {
 * public:
 *     int romanToInt(string s) {
 *         unordered_map<char, int> romanMap = {
 *             {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
 *             {'C', 100}, {'D', 500}, {'M', 1000}
 *         };
 *         
 *         int result = 0;
 *         int n = s.length();
 *         
 *         for (int i = 0; i < n; i++) {
 *             int current = romanMap[s[i]];
 *             
 *             // 如果当前字符的值小于下一个字符的值，则减去当前值
 *             if (i < n - 1 && current < romanMap[s[i + 1]]) {
 *                 result -= current;
 *             } else {
 *                 result += current;
 *             }
 *         }
 *         
 *         return result;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n) - n 是字符串长度
 * 空间复杂度：O(1) - 哈希表大小固定
 */