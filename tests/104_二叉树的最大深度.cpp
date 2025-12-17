/*
 * 题目编号: 104
 * 题目名称: 二叉树的最大深度
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * 返回它的最大深度 3。
 */

/*
@Solution
class Solution {
public:
    int maxDepth(TreeNode* root);
};
@EndSolution
*/

#include "../leetcode_framework.h"

// 树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include "../template.cpp"

// ==================== 测试代码 ====================

// 辅助函数：创建树
TreeNode* createTree(vector<int*> values) {
    if (values.empty() || values[0] == nullptr) return nullptr;
    
    TreeNode* root = new TreeNode(*values[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        // 左子节点
        if (i < values.size() && values[i] != nullptr) {
            node->left = new TreeNode(*values[i]);
            q.push(node->left);
        }
        i++;
        
        // 右子节点
        if (i < values.size() && values[i] != nullptr) {
            node->right = new TreeNode(*values[i]);
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
    
    cout << "开始测试 [104. 二叉树的最大深度]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [3,9,20,null,null,15,7]
    TreeNode* root1 = createTree({new int(3), new int(9), new int(20), 
                                  nullptr, nullptr, new int(15), new int(7)});
    RUN_TEST(solution.maxDepth(root1), 3, "测试用例 1: [3,9,20,null,null,15,7]");
    deleteTree(root1);
    
    // 测试用例 2: [1,null,2]
    TreeNode* root2 = createTree({new int(1), nullptr, new int(2)});
    RUN_TEST(solution.maxDepth(root2), 2, "测试用例 2: [1,null,2]");
    deleteTree(root2);
    
    // 测试用例 3: 空树
    TreeNode* root3 = nullptr;
    RUN_TEST(solution.maxDepth(root3), 0, "测试用例 3: 空树");
    
    // 测试用例 4: 只有根节点
    TreeNode* root4 = new TreeNode(1);
    RUN_TEST(solution.maxDepth(root4), 1, "测试用例 4: 只有根节点");
    deleteTree(root4);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这是一道经典的树的递归问题。最大深度的定义是从根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 核心思路：
 * 1. 使用递归（深度优先搜索 DFS）
 * 2. 当前节点的最大深度 = max(左子树深度, 右子树深度) + 1
 * 3. 递归的终止条件是节点为空，深度为 0
 * 
 * 【算法步骤】
 * 1. 如果根节点为空，返回 0
 * 2. 递归计算左子树的最大深度
 * 3. 递归计算右子树的最大深度
 * 4. 返回 max(左深度, 右深度) + 1
 * 
 * 【参考解法】
 * 
 * // 方法1：递归（DFS）
 * class Solution {
 * public:
 *     int maxDepth(TreeNode* root) {
 *         if (root == nullptr) {
 *             return 0;
 *         }
 *         
 *         int leftDepth = maxDepth(root->left);
 *         int rightDepth = maxDepth(root->right);
 *         
 *         return max(leftDepth, rightDepth) + 1;
 *     }
 * };
 * 
 * // 方法2：迭代（BFS 层序遍历）
 * class Solution {
 * public:
 *     int maxDepth(TreeNode* root) {
 *         if (root == nullptr) return 0;
 *         
 *         queue<TreeNode*> q;
 *         q.push(root);
 *         int depth = 0;
 *         
 *         while (!q.empty()) {
 *             int size = q.size();
 *             depth++;
 *             
 *             for (int i = 0; i < size; i++) {
 *                 TreeNode* node = q.front();
 *                 q.pop();
 *                 
 *                 if (node->left) q.push(node->left);
 *                 if (node->right) q.push(node->right);
 *             }
 *         }
 *         
 *         return depth;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（递归）：
 * - 时间复杂度：O(n) - 需要遍历所有节点
 * - 空间复杂度：O(h) - 递归调用栈的深度，h 为树的高度
 * 
 * 方法2（迭代）：
 * - 时间复杂度：O(n) - 需要遍历所有节点
 * - 空间复杂度：O(w) - 队列中最多存储 w 个节点，w 为树的最大宽度
 */
