/*
 * 题目编号: 160
 * 题目名称: 相交链表
 * 难度: 简单
 *
 * 题目描述:
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
 * 如果两个链表没有交点，返回 null。
 *
 * 示例:
 * A: a1 -> a2 \
 *              c1 -> c2 -> c3
 * B:      b1 /
 * 返回 c1
 */

#include "../leetcode_framework.h"

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
@Solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};
@EndSolution
*/

#include "../template.cpp"

// ==================== 辅助函数 ====================

ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

ListNode* tailOf(ListNode* head) {
    if (!head) return nullptr;
    while (head->next) head = head->next;
    return head;
}

void deleteListUnique(ListNode* head, unordered_set<ListNode*>& freed) {
    while (head) {
        if (freed.count(head)) return;
        freed.insert(head);
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [160. 相交链表]..." << endl;
    cout << string(50, '-') << endl;

    // 测试用例 1：有交点
    // A: 1->2->(8->9)
    // B: 3->(8->9)
    ListNode* common1 = createList({8, 9});
    ListNode* a1 = createList({1, 2});
    ListNode* b1 = createList({3});
    tailOf(a1)->next = common1;
    tailOf(b1)->next = common1;
    RUN_TEST(solution.getIntersectionNode(a1, b1) == common1, true, "测试用例 1: 有交点");

    // 释放（避免重复释放公共部分）
    unordered_set<ListNode*> freed1;
    deleteListUnique(a1, freed1);
    deleteListUnique(b1, freed1);

    // 测试用例 2：无交点
    ListNode* a2 = createList({1, 2, 3});
    ListNode* b2 = createList({4, 5});
    RUN_TEST(solution.getIntersectionNode(a2, b2) == nullptr, true, "测试用例 2: 无交点");
    unordered_set<ListNode*> freed2;
    deleteListUnique(a2, freed2);
    deleteListUnique(b2, freed2);

    // 测试用例 3：其中一个为空
    RUN_TEST(solution.getIntersectionNode(nullptr, nullptr) == nullptr, true, "测试用例 3: 都为空");

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】双指针“换头走”（最经典）
 * p 从 A 走到尾就跳到 B；q 从 B 走到尾就跳到 A。
 * 这样两者走过的总路程都是 lenA + lenB：
 * - 若有交点，会在交点相遇
 * - 若无交点，会在 nullptr 相遇
 *
 * 【常用点】
 * - 链表指针判空
 * - 不需要额外哈希表（O(1) 空间）
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
 *         ListNode* p = headA;
 *         ListNode* q = headB;
 *         while (p != q) {
 *             p = (p == nullptr) ? headB : p->next;
 *             q = (q == nullptr) ? headA : q->next;
 *         }
 *         return p;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(lenA + lenB)
 * - 空间：O(1)
 */

