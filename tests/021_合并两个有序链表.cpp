/*
 * 题目编号: 21
 * 题目名称: 合并两个有序链表
 * 难度: 简单
 * 
 * 题目描述:
 * 将两个升序链表合并为一个新的升序链表并返回。
 * 新链表是通过拼接给定的两个链表的所有节点组成的。
 * 
 * 示例 1:
 * 输入: l1 = [1,2,4], l2 = [1,3,4]
 * 输出: [1,1,2,3,4,4]
 * 
 * 示例 2:
 * 输入: l1 = [], l2 = []
 * 输出: []
 * 
 * 示例 3:
 * 输入: l1 = [], l2 = [0]
 * 输出: [0]
 * 
 * 提示:
 * - 两个链表的节点数目范围是 [0, 50]
 * - -100 <= Node.val <= 100
 * - l1 和 l2 均按非递减顺序排列
 */

/*
@Solution
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};
@EndSolution
*/

#include "../leetcode_framework.h"

// 链表节点定义（必须在 template.cpp 之前定义）
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include "../template.cpp"

// ==================== 辅助函数 ====================

// 创建链表
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// 链表转为 vector（用于测试比较）
vector<int> listToVector(ListNode* head) {
    vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// 释放链表内存
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ==================== 测试代码 ====================

int main() {
    Solution solution;
    
    cout << "开始测试 [21. 合并两个有序链表]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1
    ListNode* l1_1 = createList({1, 2, 4});
    ListNode* l1_2 = createList({1, 3, 4});
    ListNode* result1 = solution.mergeTwoLists(l1_1, l1_2);
    RUN_TEST(listToVector(result1), vector<int>({1, 1, 2, 3, 4, 4}), 
             "测试用例 1: [1,2,4] + [1,3,4]");
    freeList(result1);
    
    // 测试用例 2
    ListNode* l2_1 = createList({});
    ListNode* l2_2 = createList({});
    ListNode* result2 = solution.mergeTwoLists(l2_1, l2_2);
    RUN_TEST(listToVector(result2), vector<int>({}), 
             "测试用例 2: [] + []");
    freeList(result2);
    
    // 测试用例 3
    ListNode* l3_1 = createList({});
    ListNode* l3_2 = createList({0});
    ListNode* result3 = solution.mergeTwoLists(l3_1, l3_2);
    RUN_TEST(listToVector(result3), vector<int>({0}), 
             "测试用例 3: [] + [0]");
    freeList(result3);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 合并两个有序链表，保持有序性。可以使用迭代或递归两种方法。
 * 
 * 核心思路（迭代法）：
 * 1. 创建一个虚拟头节点（dummy node），简化边界处理
 * 2. 使用双指针遍历两个链表，每次选择较小的节点接到结果链表上
 * 3. 处理剩余节点
 * 
 * 【算法步骤】
 * 1. 创建虚拟头节点 dummy 和当前指针 current
 * 2. 当两个链表都不为空时：
 *    - 比较两个链表的当前节点值
 *    - 将较小的节点接到 current 后面
 *    - 移动相应链表的指针
 * 3. 将剩余的节点（如果有）直接接到结果链表后面
 * 4. 返回 dummy.next
 * 
 * 【参考解法1：迭代法】
 * class Solution {
 * public:
 *     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
 *         ListNode dummy(0);  // 虚拟头节点
 *         ListNode* current = &dummy;
 *         
 *         while (list1 && list2) {
 *             if (list1->val <= list2->val) {
 *                 current->next = list1;
 *                 list1 = list1->next;
 *             } else {
 *                 current->next = list2;
 *                 list2 = list2->next;
 *             }
 *             current = current->next;
 *         }
 *         
 *         // 连接剩余节点
 *         current->next = list1 ? list1 : list2;
 *         
 *         return dummy.next;
 *     }
 * };
 * 
 * 【参考解法2：递归法】
 * class Solution {
 * public:
 *     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
 *         if (!list1) return list2;
 *         if (!list2) return list1;
 *         
 *         if (list1->val <= list2->val) {
 *             list1->next = mergeTwoLists(list1->next, list2);
 *             return list1;
 *         } else {
 *             list2->next = mergeTwoLists(list1, list2->next);
 *             return list2;
 *         }
 *     }
 * };
 * 
 * 【复杂度分析】
 * 时间复杂度：O(m + n) - m 和 n 分别是两个链表的长度
 * 空间复杂度：O(1) 迭代法 / O(m + n) 递归法（递归栈空间）
 */