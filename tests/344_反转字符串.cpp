/*
 * 题目编号: 344
 * 题目名称: 反转字符串
 * 难度: 简单
 * 
 * 题目描述:
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 * 
 * 示例 1:
 * 输入: s = ["h","e","l","l","o"]
 * 输出: ["o","l","l","e","h"]
 * 
 * 示例 2:
 * 输入: s = ["H","a","n","n","a","h"]
 * 输出: ["h","a","n","n","a","H"]
 * 
 * 提示:
 * - 1 <= s.length <= 10^5
 * - s[i] 都是 ASCII 码表中的可打印字符
 */

/*
@Solution
class Solution {
public:
    void reverseString(vector<char>& s);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [344. 反转字符串]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    vector<char> expected1 = {'o', 'l', 'l', 'e', 'h'};
    solution.reverseString(s1);
    RUN_TEST(s1, expected1, "测试用例 1: [\"h\",\"e\",\"l\",\"l\",\"o\"]");
    
    // 测试用例 2
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    vector<char> expected2 = {'h', 'a', 'n', 'n', 'a', 'H'};
    solution.reverseString(s2);
    RUN_TEST(s2, expected2, "测试用例 2: [\"H\",\"a\",\"n\",\"n\",\"a\",\"h\"]");
    
    // 测试用例 3: 单个字符
    vector<char> s3 = {'a'};
    vector<char> expected3 = {'a'};
    solution.reverseString(s3);
    RUN_TEST(s3, expected3, "测试用例 3: [\"a\"] (单个字符)");
    
    // 测试用例 4: 两个字符
    vector<char> s4 = {'a', 'b'};
    vector<char> expected4 = {'b', 'a'};
    solution.reverseString(s4);
    RUN_TEST(s4, expected4, "测试用例 4: [\"a\",\"b\"]");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的双指针问题。要求原地反转，不能使用额外空间。
 * 
 * 核心思路：
 * 1. 使用双指针，一个指向开头，一个指向结尾
 * 2. 交换两个指针指向的元素
 * 3. 两个指针向中间移动
 * 4. 当两个指针相遇时，反转完成
 * 
 * 【算法步骤】
 * 1. 初始化左指针 left = 0，右指针 right = s.length - 1
 * 2. 循环：当 left < right
 *    - 交换 s[left] 和 s[right]
 *    - left++, right--
 * 3. 反转完成
 * 
 * 【参考解法】
 * 
 * // 方法1：双指针（标准解法）
 * class Solution {
 * public:
 *     void reverseString(vector<char>& s) {
 *         int left = 0;
 *         int right = s.size() - 1;
 *         
 *         while (left < right) {
 *             // 交换左右两个字符
 *             char temp = s[left];
 *             s[left] = s[right];
 *             s[right] = temp;
 *             
 *             // 移动指针
 *             left++;
 *             right--;
 *         }
 *     }
 * };
 * 
 * // 方法2：使用 STL swap
 * class Solution {
 * public:
 *     void reverseString(vector<char>& s) {
 *         int left = 0;
 *         int right = s.size() - 1;
 *         
 *         while (left < right) {
 *             swap(s[left], s[right]);
 *             left++;
 *             right--;
 *         }
 *     }
 * };
 * 
 * // 方法3：使用 STL reverse
 * class Solution {
 * public:
 *     void reverseString(vector<char>& s) {
 *         reverse(s.begin(), s.end());
 *     }
 * };
 * 
 * // 方法4：递归（不推荐，空间复杂度 O(n)）
 * class Solution {
 * public:
 *     void reverseString(vector<char>& s) {
 *         helper(s, 0, s.size() - 1);
 *     }
 *     
 * private:
 *     void helper(vector<char>& s, int left, int right) {
 *         if (left >= right) {
 *             return;
 *         }
 *         
 *         swap(s[left], s[right]);
 *         helper(s, left + 1, right - 1);
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1-3（双指针/STL）：
 * - 时间复杂度：O(n) - n 为字符串长度，需要交换 n/2 次
 * - 空间复杂度：O(1) - 只用了两个指针变量
 * 
 * 方法4（递归）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(n) - 递归调用栈的深度
 * 
 * 【知识点】
 * - 双指针技巧
 * - 原地算法
 * - 字符串/数组反转
 * - 递归思想
 * 
 * 【注意事项】
 * - 题目要求原地修改，空间复杂度必须是 O(1)
 * - 递归虽然代码简洁，但不满足空间要求
 * - 面试时推荐方法1或方法2
 */
