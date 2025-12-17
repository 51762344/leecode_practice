/*
 * 题目编号: 141
 * 题目名称: 环形链表
 * 难度: 简单
 * 
 * 题目描述:
 * 给你一个链表的头节点 head ，判断链表中是否有环。
 * 
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 * 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置
 * （索引从 0 开始）。注意：pos 不作为参数进行传递。仅仅是为了标识链表的实际情况。
 * 
 * 如果链表中存在环，则返回 true。否则，返回 false。
 * 
 * 示例 1:
 * 输入: head = [3,2,0,-4], pos = 1
 * 输出: true
 * 解释: 链表中有一个环，其尾部连接到第二个节点。
 * 
 * 示例 2:
 * 输入: head = [1,2], pos = 0
 * 输出: true
 * 解释: 链表中有一个环，其尾部连接到第一个节点。
 * 
 * 示例 3:
 * 输入: head = [1], pos = -1
 * 输出: false
 * 解释: 链表中没有环。
 * 
 * 提示:
 * - 链表中节点的数目范围是 [0, 10^4]
 * - -10^5 <= Node.val <= 10^5
 * - pos 为 -1 或者链表中的一个有效索引
 * 
 * 进阶: 你能用 O(1)（即，常量）内存解决此问题吗？
 */

/*
@Solution
class Solution {
public:
    bool hasCycle(ListNode *head);
};
@EndSolution
*/

#include "../leetcode_framework.h"

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include "../template.cpp"

// ==================== 测试代码 ====================

// 辅助函数：创建链表（带环）
ListNode* createList(vector<int> values, int pos) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleNode = nullptr;
    
    if (pos == 0) cycleNode = head;
    
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
        if (i == pos) cycleNode = current;
    }
    
    // 创建环
    if (pos >= 0) {
        current->next = cycleNode;
    }
    
    return head;
}

// 辅助函数：删除链表（注意处理环）
void deleteList(ListNode* head, int pos) {
    if (!head) return;
    
    vector<ListNode*> nodes;
    ListNode* current = head;
    
    // 收集所有节点
    if (pos < 0) {
        // 无环，直接遍历删除
        while (current) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    } else {
        // 有环，需要断开环后删除
        unordered_set<ListNode*> visited;
        while (current && visited.find(current) == visited.end()) {
            visited.insert(current);
            nodes.push_back(current);
            current = current->next;
        }
        
        for (auto node : nodes) {
            delete node;
        }
    }
}

int main() {
    Solution solution;
    
    cout << "开始测试 [141. 环形链表]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [3,2,0,-4], pos = 1
    ListNode* head1 = createList({3, 2, 0, -4}, 1);
    RUN_TEST(solution.hasCycle(head1), true, "测试用例 1: [3,2,0,-4], pos=1");
    deleteList(head1, 1);
    
    // 测试用例 2: [1,2], pos = 0
    ListNode* head2 = createList({1, 2}, 0);
    RUN_TEST(solution.hasCycle(head2), true, "测试用例 2: [1,2], pos=0");
    deleteList(head2, 0);
    
    // 测试用例 3: [1], pos = -1
    ListNode* head3 = createList({1}, -1);
    RUN_TEST(solution.hasCycle(head3), false, "测试用例 3: [1], pos=-1 (无环)");
    deleteList(head3, -1);
    
    // 测试用例 4: 空链表
    ListNode* head4 = nullptr;
    RUN_TEST(solution.hasCycle(head4), false, "测试用例 4: 空链表");
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的快慢指针问题（Floyd's Cycle Detection Algorithm，也叫龟兔赛跑算法）。
 * 
 * 核心思路：
 * 1. 使用两个指针：慢指针（每次走一步）和快指针（每次走两步）
 * 2. 如果链表有环，快指针最终会追上慢指针
 * 3. 如果链表无环，快指针会先到达链表末尾（nullptr）
 * 
 * 【算法步骤】
 * 1. 初始化两个指针 slow 和 fast 都指向 head
 * 2. 循环：
 *    - slow 每次走一步：slow = slow->next
 *    - fast 每次走两步：fast = fast->next->next
 *    - 如果 fast 或 fast->next 为空，返回 false（无环）
 *    - 如果 slow == fast，返回 true（有环）
 * 
 * 【参考解法】
 * 
 * // 方法1：快慢指针（最优解，O(1) 空间）
 * class Solution {
 * public:
 *     bool hasCycle(ListNode *head) {
 *         if (head == nullptr || head->next == nullptr) {
 *             return false;
 *         }
 *         
 *         ListNode* slow = head;
 *         ListNode* fast = head;
 *         
 *         while (fast != nullptr && fast->next != nullptr) {
 *             slow = slow->next;          // 慢指针走一步
 *             fast = fast->next->next;    // 快指针走两步
 *             
 *             if (slow == fast) {
 *                 return true;  // 相遇，说明有环
 *             }
 *         }
 *         
 *         return false;  // 快指针到达末尾，无环
 *     }
 * };
 * 
 * // 方法2：哈希表（空间复杂度 O(n)）
 * class Solution {
 * public:
 *     bool hasCycle(ListNode *head) {
 *         unordered_set<ListNode*> visited;
 *         
 *         ListNode* current = head;
 *         while (current != nullptr) {
 *             // 如果节点已访问过，说明有环
 *             if (visited.find(current) != visited.end()) {
 *                 return true;
 *             }
 *             visited.insert(current);
 *             current = current->next;
 *         }
 *         
 *         return false;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（快慢指针）：
 * - 时间复杂度：O(n) - n 为链表长度
 *   - 无环：快指针遍历 n/2 个节点
 *   - 有环：最多遍历环的长度次
 * - 空间复杂度：O(1) - 只用了两个指针
 * 
 * 方法2（哈希表）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(n) - 需要存储所有节点
 * 
 * 【知识点】
 * - 快慢指针（Floyd判圈算法）
 * - 这个算法的证明：如果有环，快指针和慢指针一定会相遇
 *   因为快指针每次比慢指针多走一步，相对速度是1，所以一定能追上
 */
