/*
 * 题目编号: 19
 * 题目名称: 删除链表的倒数第 N 个结点
 * 难度: 中等
 * 
 * 题目描述:
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 示例 1:
 * 输入: head = [1,2,3,4,5], n = 2
 * 输出: [1,2,3,5]
 * 
 * 示例 2:
 * 输入: head = [1], n = 1
 * 输出: []
 * 
 * 示例 3:
 * 输入: head = [1,2], n = 1
 * 输出: [1]
 * 
 * 提示:
 * - 链表中结点的数目为 sz
 * - 1 <= sz <= 30
 * - 0 <= Node.val <= 100
 * - 1 <= n <= sz
 * 
 * 进阶: 你能尝试使用一趟扫描实现吗？
 */

/*
@Solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
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

// 辅助函数：链表转数组
vector<int> listToArray(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
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
    
    cout << "开始测试 [19. 删除链表的倒数第 N 个结点]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [1,2,3,4,5], n = 2
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.removeNthFromEnd(head1, 2);
    vector<int> expected1 = {1, 2, 3, 5};
    RUN_TEST(listToArray(result1), expected1, "测试用例 1: [1,2,3,4,5], n=2");
    deleteList(result1);
    
    // 测试用例 2: [1], n = 1
    ListNode* head2 = createList({1});
    ListNode* result2 = solution.removeNthFromEnd(head2, 1);
    vector<int> expected2 = {};
    RUN_TEST(listToArray(result2), expected2, "测试用例 2: [1], n=1");
    deleteList(result2);
    
    // 测试用例 3: [1,2], n = 1
    ListNode* head3 = createList({1, 2});
    ListNode* result3 = solution.removeNthFromEnd(head3, 1);
    vector<int> expected3 = {1};
    RUN_TEST(listToArray(result3), expected3, "测试用例 3: [1,2], n=1");
    deleteList(result3);
    
    // 测试用例 4: [1,2], n = 2 (删除头节点)
    ListNode* head4 = createList({1, 2});
    ListNode* result4 = solution.removeNthFromEnd(head4, 2);
    vector<int> expected4 = {2};
    RUN_TEST(listToArray(result4), expected4, "测试用例 4: [1,2], n=2 (删除头节点)");
    deleteList(result4);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 删除链表的倒数第 N 个节点。关键问题是如何一次遍历就找到倒数第 N 个节点。
 * 
 * 核心思路：
 * 1. 使用快慢双指针
 * 2. 快指针先走 n 步
 * 3. 然后快慢指针一起走，当快指针到达末尾时，慢指针正好在倒数第 n+1 个节点
 * 4. 删除慢指针的下一个节点
 * 
 * 【算法步骤】
 * 1. 创建哑节点（dummy node）指向 head，处理删除头节点的情况
 * 2. 初始化快慢指针都指向 dummy
 * 3. 快指针先走 n+1 步
 * 4. 快慢指针一起走，直到快指针到达末尾
 * 5. 删除慢指针的下一个节点：slow->next = slow->next->next
 * 6. 返回 dummy->next
 * 
 * 【参考解法】
 * 
 * // 方法1：双指针（一次遍历）
 * class Solution {
 * public:
 *     ListNode* removeNthFromEnd(ListNode* head, int n) {
 *         // 创建哑节点，简化边界情况处理
 *         ListNode* dummy = new ListNode(0);
 *         dummy->next = head;
 *         
 *         ListNode* fast = dummy;
 *         ListNode* slow = dummy;
 *         
 *         // 快指针先走 n+1 步
 *         for (int i = 0; i <= n; i++) {
 *             fast = fast->next;
 *         }
 *         
 *         // 快慢指针一起走
 *         while (fast != nullptr) {
 *             fast = fast->next;
 *             slow = slow->next;
 *         }
 *         
 *         // 删除倒数第 n 个节点
 *         ListNode* toDelete = slow->next;
 *         slow->next = slow->next->next;
 *         delete toDelete;
 *         
 *         ListNode* newHead = dummy->next;
 *         delete dummy;
 *         return newHead;
 *     }
 * };
 * 
 * // 方法2：两次遍历
 * class Solution {
 * public:
 *     ListNode* removeNthFromEnd(ListNode* head, int n) {
 *         // 第一次遍历：计算链表长度
 *         int length = 0;
 *         ListNode* current = head;
 *         while (current != nullptr) {
 *             length++;
 *             current = current->next;
 *         }
 *         
 *         // 创建哑节点
 *         ListNode* dummy = new ListNode(0);
 *         dummy->next = head;
 *         
 *         // 第二次遍历：找到要删除节点的前一个节点
 *         current = dummy;
 *         for (int i = 0; i < length - n; i++) {
 *             current = current->next;
 *         }
 *         
 *         // 删除节点
 *         ListNode* toDelete = current->next;
 *         current->next = current->next->next;
 *         delete toDelete;
 *         
 *         ListNode* newHead = dummy->next;
 *         delete dummy;
 *         return newHead;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（双指针）：
 * - 时间复杂度：O(L) - L 为链表长度，只需一次遍历
 * - 空间复杂度：O(1) - 只用了两个指针
 * 
 * 方法2（两次遍历）：
 * - 时间复杂度：O(L) - 需要遍历两次
 * - 空间复杂度：O(1)
 * 
 * 【知识点】
 * - 双指针技巧（快慢指针）
 * - 哑节点（dummy node）的使用
 * - 链表删除操作
 * - 倒数第 N 个节点的定位
 * 
 * 【关键点】
 * 1. 使用哑节点可以统一处理删除头节点和其他节点的情况
 * 2. 快指针先走 n+1 步，这样慢指针最后会停在要删除节点的前一个节点
 * 3. 记得释放内存（C++ 特有）
 * 
 * 【面试技巧】
 * - 可以先说两次遍历的方法，再提出一次遍历的优化
 * - 讨论边界情况：删除头节点、只有一个节点等
 */
