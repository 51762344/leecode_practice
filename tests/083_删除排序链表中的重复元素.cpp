/*
 * 题目编号: 83
 * 题目名称: 删除排序链表中的重复元素
 * 难度: 简单
 *
 * 题目描述:
 * 给定一个已排序的链表的头 head ，删除所有重复的元素，使每个元素只出现一次。
 * 返回已排序的链表。
 *
 * 示例 1:
 * 输入: head = [1,1,2]
 * 输出: [1,2]
 *
 * 示例 2:
 * 输入: head = [1,1,2,3,3]
 * 输出: [1,2,3]
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
    ListNode* deleteDuplicates(ListNode* head);
};
@EndSolution
*/

#include "../leetcode_framework.h"
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

vector<int> listToArray(ListNode* head) {
    vector<int> res;
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    return res;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [83. 删除排序链表中的重复元素]..." << endl;
    cout << string(50, '-') << endl;

    ListNode* h1 = createList({1, 1, 2});
    ListNode* r1 = solution.deleteDuplicates(h1);
    RUN_TEST(listToArray(r1), vector<int>({1, 2}), "测试用例 1: [1,1,2]");
    deleteList(r1);

    ListNode* h2 = createList({1, 1, 2, 3, 3});
    ListNode* r2 = solution.deleteDuplicates(h2);
    RUN_TEST(listToArray(r2), vector<int>({1, 2, 3}), "测试用例 2: [1,1,2,3,3]");
    deleteList(r2);

    ListNode* h3 = createList({});
    ListNode* r3 = solution.deleteDuplicates(h3);
    RUN_TEST(listToArray(r3), vector<int>({}), "测试用例 3: []");
    deleteList(r3);

    ListNode* h4 = createList({1});
    ListNode* r4 = solution.deleteDuplicates(h4);
    RUN_TEST(listToArray(r4), vector<int>({1}), "测试用例 4: [1]");
    deleteList(r4);

    ListNode* h5 = createList({1, 1, 1});
    ListNode* r5 = solution.deleteDuplicates(h5);
    RUN_TEST(listToArray(r5), vector<int>({1}), "测试用例 5: [1,1,1]");
    deleteList(r5);

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】一次遍历 + 指针跳过重复
 * 链表已排序，重复元素一定相邻。
 * 用 cur 指针扫过去：
 * - 若 cur->val == cur->next->val：删除/跳过 next（cur->next = cur->next->next）
 * - 否则 cur 往前走
 *
 * 【常用点】
 * - 指针判空（cur && cur->next）
 * - 释放内存（这里参考解法用 delete，面试可不强调；你自己的框架里也常写）
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     ListNode* deleteDuplicates(ListNode* head) {
 *         ListNode* cur = head;
 *         while (cur && cur->next) {
 *             if (cur->val == cur->next->val) {
 *                 ListNode* dup = cur->next;
 *                 cur->next = cur->next->next;
 *                 delete dup;
 *             } else {
 *                 cur = cur->next;
 *             }
 *         }
 *         return head;
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n)
 * - 空间：O(1)
 */

