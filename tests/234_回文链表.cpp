/*
 * 题目编号: 234
 * 题目名称: 回文链表
 * 难度: 简单
 * 
 * 题目描述:
 * 给你一个单链表的头节点 head，请你判断该链表是否为回文链表。
 * 如果是，返回 true；否则，返回 false。
 * 
 * 示例 1:
 * 输入: head = [1,2,2,1]
 * 输出: true
 * 
 * 示例 2:
 * 输入: head = [1,2]
 * 输出: false
 * 
 * 提示:
 * - 链表中节点数目在范围 [1, 10^5] 内
 * - 0 <= Node.val <= 9
 * 
 * 进阶: 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 */

/*
@Solution
class Solution {
public:
    bool isPalindrome(ListNode* head);
};
@EndSolution
*/

#include "../leetcode_framework.h"

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include "../template.cpp"

// ==================== 测试代码 ====================

// 辅助函数：创建链表
ListNode* createList(vector<int> values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

// 辅助函数：删除链表
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;
    
    cout << "开始测试 [234. 回文链表]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [1,2,2,1]
    ListNode* head1 = createList({1, 2, 2, 1});
    RUN_TEST(solution.isPalindrome(head1), true, "测试用例 1: [1,2,2,1]");
    deleteList(head1);
    
    // 测试用例 2: [1,2]
    ListNode* head2 = createList({1, 2});
    RUN_TEST(solution.isPalindrome(head2), false, "测试用例 2: [1,2]");
    deleteList(head2);
    
    // 测试用例 3: [1]
    ListNode* head3 = createList({1});
    RUN_TEST(solution.isPalindrome(head3), true, "测试用例 3: [1] (单节点)");
    deleteList(head3);
    
    // 测试用例 4: [1,2,3,2,1]
    ListNode* head4 = createList({1, 2, 3, 2, 1});
    RUN_TEST(solution.isPalindrome(head4), true, "测试用例 4: [1,2,3,2,1]");
    deleteList(head4);
    
    // 测试用例 5: [1,2,3,4,5]
    ListNode* head5 = createList({1, 2, 3, 4, 5});
    RUN_TEST(solution.isPalindrome(head5), false, "测试用例 5: [1,2,3,4,5]");
    deleteList(head5);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 判断链表是否为回文。回文的特点是正着读和反着读都一样。
 * 
 * 核心思路：
 * 1. 找到链表的中点（使用快慢指针）
 * 2. 反转后半部分链表
 * 3. 比较前半部分和反转后的后半部分
 * 4. 恢复链表（可选）
 * 
 * 【算法步骤】
 * 1. 使用快慢指针找到链表中点
 *    - slow 每次走一步，fast 每次走两步
 *    - 当 fast 到达末尾时，slow 在中点
 * 2. 反转后半部分链表
 * 3. 比较前半部分和后半部分的值
 * 4. 返回结果
 * 
 * 【参考解法】
 * 
 * // 方法1：快慢指针 + 反转链表（O(1) 空间）
 * class Solution {
 * public:
 *     bool isPalindrome(ListNode* head) {
 *         if (head == nullptr || head->next == nullptr) {
 *             return true;
 *         }
 *         
 *         // 1. 找到链表中点
 *         ListNode* slow = head;
 *         ListNode* fast = head;
 *         while (fast->next != nullptr && fast->next->next != nullptr) {
 *             slow = slow->next;
 *             fast = fast->next->next;
 *         }
 *         
 *         // 2. 反转后半部分链表
 *         ListNode* secondHalf = reverseList(slow->next);
 *         
 *         // 3. 比较前半部分和后半部分
 *         ListNode* p1 = head;
 *         ListNode* p2 = secondHalf;
 *         bool result = true;
 *         
 *         while (p2 != nullptr) {
 *             if (p1->val != p2->val) {
 *                 result = false;
 *                 break;
 *             }
 *             p1 = p1->next;
 *             p2 = p2->next;
 *         }
 *         
 *         // 4. 恢复链表（可选）
 *         slow->next = reverseList(secondHalf);
 *         
 *         return result;
 *     }
 *     
 * private:
 *     ListNode* reverseList(ListNode* head) {
 *         ListNode* prev = nullptr;
 *         ListNode* curr = head;
 *         
 *         while (curr != nullptr) {
 *             ListNode* next = curr->next;
 *             curr->next = prev;
 *             prev = curr;
 *             curr = next;
 *         }
 *         
 *         return prev;
 *     }
 * };
 * 
 * // 方法2：数组存储（O(n) 空间）
 * class Solution {
 * public:
 *     bool isPalindrome(ListNode* head) {
 *         vector<int> values;
 *         
 *         // 将链表值存入数组
 *         ListNode* current = head;
 *         while (current != nullptr) {
 *             values.push_back(current->val);
 *             current = current->next;
 *         }
 *         
 *         // 双指针比较
 *         int left = 0, right = values.size() - 1;
 *         while (left < right) {
 *             if (values[left] != values[right]) {
 *                 return false;
 *             }
 *             left++;
 *             right--;
 *         }
 *         
 *         return true;
 *     }
 * };
 * 
 * // 方法3：递归（O(n) 空间）
 * class Solution {
 * private:
 *     ListNode* frontPointer;
 *     
 *     bool recursiveCheck(ListNode* current) {
 *         if (current != nullptr) {
 *             if (!recursiveCheck(current->next)) {
 *                 return false;
 *             }
 *             if (current->val != frontPointer->val) {
 *                 return false;
 *             }
 *             frontPointer = frontPointer->next;
 *         }
 *         return true;
 *     }
 *     
 * public:
 *     bool isPalindrome(ListNode* head) {
 *         frontPointer = head;
 *         return recursiveCheck(head);
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（快慢指针 + 反转）：
 * - 时间复杂度：O(n) - 遍历链表
 * - 空间复杂度：O(1) - 只用了几个指针
 * 
 * 方法2（数组）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(n) - 需要额外数组存储所有值
 * 
 * 方法3（递归）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(n) - 递归调用栈
 * 
 * 【知识点】
 * - 快慢指针找中点
 * - 反转链表
 * - 回文判断
 * - 链表的递归处理
 */
