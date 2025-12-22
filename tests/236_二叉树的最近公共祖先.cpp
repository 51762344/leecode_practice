/*
 * 题目编号: 236
 * 题目名称: 二叉树的最近公共祖先
 * 难度: 中等
 * 
 * 题目描述:
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为："对于有根树 T 的两个节点 p、q，
 * 最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大
 * （一个节点也可以是它自己的祖先）。"
 * 
 * 示例 1：
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 * 
 *       3
 *      / \
 *     5   1
 *    / \ / \
 *   6  2 0  8
 *     / \
 *    7   4
 * 
 * 示例 2：
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 示例 3：
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 * 
 * 提示：
 * - 树中节点数目在范围 [2, 10^5] 内。
 * - -10^9 <= Node.val <= 10^9
 * - 所有 Node.val 互不相同。
 * - p != q
 * - p 和 q 均存在于给定的二叉树中。
 */

/*
@Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};
@EndSolution
*/

#include "../leetcode_framework.h"

// 树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include "../template.cpp"

// ==================== 测试代码 ====================

// 辅助函数：创建树并返回特定值的节点
TreeNode* createTreeAndFind(vector<int*> values, int targetVal, TreeNode** target) {
    if (values.empty() || values[0] == nullptr) return nullptr;
    
    TreeNode* root = new TreeNode(*values[0]);
    if (*values[0] == targetVal) *target = root;
    
    queue<TreeNode*> q;
    q.push(root);
    
    size_t i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        // 左子节点
        if (i < values.size() && values[i] != nullptr) {
            node->left = new TreeNode(*values[i]);
            if (*values[i] == targetVal) *target = node->left;
            q.push(node->left);
        }
        i++;
        
        // 右子节点
        if (i < values.size() && values[i] != nullptr) {
            node->right = new TreeNode(*values[i]);
            if (*values[i] == targetVal) *target = node->right;
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}

// 辅助函数：删除树
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;
    
    cout << "开始测试 [236. 二叉树的最近公共祖先]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    TreeNode *p1 = nullptr, *q1 = nullptr;
    TreeNode* root1 = createTreeAndFind({new int(3), new int(5), new int(1), new int(6), 
                                         new int(2), new int(0), new int(8), nullptr, 
                                         nullptr, new int(7), new int(4)}, 5, &p1);
    createTreeAndFind({new int(3), new int(5), new int(1), new int(6), 
                      new int(2), new int(0), new int(8), nullptr, 
                      nullptr, new int(7), new int(4)}, 1, &q1);
    // 手动设置指针（简化测试）
    p1 = root1->left;  // 节点 5
    q1 = root1->right; // 节点 1
    TreeNode* result1 = solution.lowestCommonAncestor(root1, p1, q1);
    test_framework.assert_equal(3, result1->val, "测试用例 1: p=5, q=1, 期望=3");
    deleteTree(root1);
    
    // 测试用例 2: [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(2);
    root2->left->right->left = new TreeNode(7);
    root2->left->right->right = new TreeNode(4);
    root2->right->left = new TreeNode(0);
    root2->right->right = new TreeNode(8);
    
    TreeNode* p2 = root2->left;  // 节点 5
    TreeNode* q2 = root2->left->right->right;  // 节点 4
    TreeNode* result2 = solution.lowestCommonAncestor(root2, p2, q2);
    test_framework.assert_equal(5, result2->val, "测试用例 2: p=5, q=4, 期望=5");
    deleteTree(root2);
    
    // 测试用例 3: [1,2], p = 1, q = 2
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    TreeNode* p3 = root3;  // 节点 1
    TreeNode* q3 = root3->left;  // 节点 2
    TreeNode* result3 = solution.lowestCommonAncestor(root3, p3, q3);
    test_framework.assert_equal(1, result3->val, "测试用例 3: p=1, q=2, 期望=1");
    deleteTree(root3);
    
    // 测试用例 4: 简单二叉树
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    TreeNode* p4 = root4->left;  // 节点 2
    TreeNode* q4 = root4->right;  // 节点 3
    TreeNode* result4 = solution.lowestCommonAncestor(root4, p4, q4);
    test_framework.assert_equal(1, result4->val, "测试用例 4: p=2, q=3, 期望=1");
    deleteTree(root4);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道二叉树经典题目，面试**超高频**（字节、腾讯、阿里必考）。
 * 
 * 核心思想：
 * 使用**后序遍历**（左 → 右 → 根）的递归思路：
 * 1. 如果当前节点是 p 或 q，返回当前节点
 * 2. 递归查找左子树和右子树
 * 3. 根据左右子树的返回值判断：
 *    - 如果左右子树都找到了，说明当前节点就是最近公共祖先
 *    - 如果只有一边找到，返回找到的那一边
 * 
 * 【算法步骤】
 * 1. 终止条件：
 *    - 如果 root 为空，返回 null
 *    - 如果 root 是 p 或 q，返回 root
 * 
 * 2. 递归左右子树：
 *    - left = lowestCommonAncestor(root.left, p, q)
 *    - right = lowestCommonAncestor(root.right, p, q)
 * 
 * 3. 根据返回值判断：
 *    - 如果 left 和 right 都不为空，说明 p 和 q 分别在左右子树，root 就是 LCA
 *    - 如果 left 为空，说明 p 和 q 都在右子树，返回 right
 *    - 如果 right 为空，说明 p 和 q 都在左子树，返回 left
 * 
 * 【参考解法】
 * 
 * // 方法1：递归（后序遍历）
 * class Solution {
 * public:
 *     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
 *         // 终止条件
 *         if (root == nullptr) return nullptr;
 *         if (root == p || root == q) return root;
 *         
 *         // 递归左右子树
 *         TreeNode* left = lowestCommonAncestor(root->left, p, q);
 *         TreeNode* right = lowestCommonAncestor(root->right, p, q);
 *         
 *         // 根据返回值判断
 *         if (left != nullptr && right != nullptr) {
 *             // p 和 q 分别在左右子树
 *             return root;
 *         }
 *         
 *         // 返回非空的那一边
 *         return left != nullptr ? left : right;
 *     }
 * };
 * 
 * // 方法2：递归（简化版）
 * class Solution {
 * public:
 *     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
 *         if (!root || root == p || root == q) return root;
 *         
 *         TreeNode* left = lowestCommonAncestor(root->left, p, q);
 *         TreeNode* right = lowestCommonAncestor(root->right, p, q);
 *         
 *         if (!left) return right;
 *         if (!right) return left;
 *         return root;
 *     }
 * };
 * 
 * 【复杂度分析】
 * - 时间复杂度：O(n) - 最坏情况需要遍历所有节点
 * - 空间复杂度：O(h) - 递归调用栈的深度，h 为树的高度
 * 
 * 【关键点】
 * 1. **后序遍历**：先处理子树，再处理根节点
 * 2. **递归返回值的含义**：
 *    - 返回 null：子树中没有 p 和 q
 *    - 返回非 null：子树中找到了 p 或 q，或者找到了 LCA
 * 3. **三种情况**：
 *    - p 和 q 在不同子树：root 是 LCA
 *    - p 和 q 在同一子树：返回非空的那一边
 *    - p 是 q 的祖先（或反过来）：返回先遇到的那个节点
 * 
 * 【图解示例】
 * 对于树：
 *       3
 *      / \
 *     5   1
 *    / \
 *   6   2
 *      / \
 *     7   4
 * 
 * 查找 p=5, q=1 的 LCA：
 * 1. 从根节点 3 开始
 * 2. 左子树找到 5，右子树找到 1
 * 3. 因为左右都找到了，所以 3 是 LCA
 * 
 * 查找 p=5, q=4 的 LCA：
 * 1. 从根节点 3 开始
 * 2. 左子树返回 5（因为 5 本身被找到）
 * 3. 右子树返回 null
 * 4. 返回 5（LCA 是 5 本身）
 * 
 * 【面试高频程度】⭐⭐⭐⭐⭐
 * - 字节跳动：超高频
 * - 腾讯：超高频
 * - 阿里：高频
 * - 美团：高频
 * 
 * 【变体题目】
 * - LeetCode 235: 二叉搜索树的最近公共祖先（利用 BST 性质）
 * - LeetCode 1644: 二叉树的最近公共祖先 II（p 或 q 可能不存在）
 * - LeetCode 1650: 二叉树的最近公共祖先 III（节点有父指针）
 */

