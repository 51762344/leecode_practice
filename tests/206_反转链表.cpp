/*
 * 题目编号: 206
 * 题目名称: 反转链表
 * 难度: 简单
 * 
 * 题目描述:
 * 给你单链表的头节点 head，请你反转链表，并返回反转后的链表。
 * 
 * 示例 1:
 * 输入: head = [1,2,3,4,5]
 * 输出: [5,4,3,2,1]
 * 
 * 示例 2:
 * 输入: head = [1,2]
 * 输出: [2,1]
 * 
 * 示例 3:
 * 输入: head = []
 * 输出: []
 * 
 * 提示:
 * - 链表中节点的数目范围是 [0, 5000]
 * - -5000 <= Node.val <= 5000
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 */

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
@Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head);
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 辅助函数 ====================

// 从数组创建链表
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// 链表转换为数组
vector<int> listToArray(ListNode* head) {
    vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// 释放链表内存
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [206. 反转链表]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.reverseList(head1);
    vector<int> expected1 = {5, 4, 3, 2, 1};
    RUN_TEST(listToArray(result1), expected1, 
             "测试用例 1: [1,2,3,4,5]");
    deleteList(result1);
    
    // 测试用例 2
    ListNode* head2 = createList({1, 2});
    ListNode* result2 = solution.reverseList(head2);
    vector<int> expected2 = {2, 1};
    RUN_TEST(listToArray(result2), expected2, 
             "测试用例 2: [1,2]");
    deleteList(result2);
    
    // 测试用例 3：空链表
    ListNode* head3 = createList({});
    ListNode* result3 = solution.reverseList(head3);
    vector<int> expected3 = {};
    RUN_TEST(listToArray(result3), expected3, 
             "测试用例 3: []");
    deleteList(result3);
    
    // 测试用例 4：只有一个节点
    ListNode* head4 = createList({1});
    ListNode* result4 = solution.reverseList(head4);
    vector<int> expected4 = {1};
    RUN_TEST(listToArray(result4), expected4, 
             "测试用例 4: [1]");
    deleteList(result4);
    
    // 测试用例 5：两个相同的元素
    ListNode* head5 = createList({5, 5});
    ListNode* result5 = solution.reverseList(head5);
    vector<int> expected5 = {5, 5};
    RUN_TEST(listToArray(result5), expected5, 
             "测试用例 5: [5,5]");
    deleteList(result5);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 反转链表是链表操作的基础题目，有迭代和递归两种经典解法。
 * 
 * 核心思路（迭代法）：
 * 使用三个指针：prev（前一个节点）、curr（当前节点）、next（下一个节点）
 * 逐个反转节点的指向。
 * 
 * 【算法步骤（迭代法）】
 * 1. 初始化 prev = nullptr, curr = head
 * 2. 当 curr 不为空时：
 *    - 保存下一个节点：next = curr->next
 *    - 反转当前节点：curr->next = prev
 *    - 移动指针：prev = curr, curr = next
 * 3. 返回 prev（新的头节点）
 * 
 * 【参考解法1：迭代法】
 * class Solution {
 * public:
 *     ListNode* reverseList(ListNode* head) {
 *         ListNode* prev = nullptr;
 *         ListNode* curr = head;
 *         
 *         while (curr != nullptr) {
 *             ListNode* next = curr->next;  // 保存下一个节点
 *             curr->next = prev;            // 反转当前节点
 *             prev = curr;                  // 移动 prev
 *             curr = next;                  // 移动 curr
 *         }
 *         
 *         return prev;
 *     }
 * };
 * 
 * 【参考解法2：递归法】
 * 递归思路：
 * 1. 递归反转后面的链表
 * 2. 将当前节点接到反转后的链表末尾
 * 
 * class Solution {
 * public:
 *     ListNode* reverseList(ListNode* head) {
 *         // 基础情况：空链表或只有一个节点
 *         if (head == nullptr || head->next == nullptr) {
 *             return head;
 *         }
 *         
 *         // 递归反转后面的链表
 *         ListNode* newHead = reverseList(head->next);
 *         
 *         // 将当前节点接到反转后的链表末尾
 *         // head->next 现在指向反转后链表的最后一个节点
 *         head->next->next = head;
 *         head->next = nullptr;
 *         
 *         return newHead;
 *     }
 * };
 * 
 * 【图解（迭代法）】
 * 原链表：1 -> 2 -> 3 -> 4 -> 5 -> null
 * 
 * 初始：prev=null, curr=1
 * 步骤1：null <- 1    2 -> 3 -> 4 -> 5
 * 步骤2：null <- 1 <- 2    3 -> 4 -> 5
 * 步骤3：null <- 1 <- 2 <- 3    4 -> 5
 * 步骤4：null <- 1 <- 2 <- 3 <- 4    5
 * 步骤5：null <- 1 <- 2 <- 3 <- 4 <- 5
 * 
 * 【复杂度分析】
 * 时间复杂度：O(n)
 * 空间复杂度：O(1) 迭代法 / O(n) 递归法（递归栈）
 */
