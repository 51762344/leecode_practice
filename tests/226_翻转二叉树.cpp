/*
 * 题目编号: 226
 * 题目名称: 翻转二叉树
 * 难度: 简单
 * 
 * 题目描述:
 * 给你一棵二叉树的根节点 root，翻转这棵二叉树，并返回其根节点。
 * 
 * 示例 1:
 * 输入: root = [4,2,7,1,3,6,9]
 * 输出: [4,7,2,9,6,3,1]
 * 
 *      4                4
 *    /   \            /   \
 *   2     7    =>    7     2
 *  / \   / \        / \   / \
 * 1   3 6   9      9   6 3   1
 * 
 * 示例 2:
 * 输入: root = [2,1,3]
 * 输出: [2,3,1]
 * 
 * 示例 3:
 * 输入: root = []
 * 输出: []
 * 
 * 提示:
 * - 树中节点数目范围在 [0, 100] 内
 * - -100 <= Node.val <= 100
 * 
 * 【趣闻】
 * 据说这道题曾经在 Google 面试中考倒了 Homebrew 的作者 Max Howell，
 * 他后来在 Twitter 上吐槽："Google: 90% of our engineers use the software you wrote (Homebrew),
 * but you can't invert a binary tree on a whiteboard so f*** off."
 */

/*
@Solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root);
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
        
        if (i < values.size() && values[i] != nullptr) {
            node->left = new TreeNode(*values[i]);
            q.push(node->left);
        }
        i++;
        
        if (i < values.size() && values[i] != nullptr) {
            node->right = new TreeNode(*values[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}

// 辅助函数：层序遍历转为数组（用于比较）
vector<int> treeToArray(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        result.push_back(node->val);
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    
    return result;
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
    
    cout << "开始测试 [226. 翻转二叉树]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [4,2,7,1,3,6,9]
    TreeNode* root1 = createTree({new int(4), new int(2), new int(7), 
                                  new int(1), new int(3), new int(6), new int(9)});
    TreeNode* result1 = solution.invertTree(root1);
    vector<int> expected1 = {4, 7, 2, 9, 6, 3, 1};
    RUN_TEST(treeToArray(result1), expected1, "测试用例 1: [4,2,7,1,3,6,9]");
    deleteTree(result1);
    
    // 测试用例 2: [2,1,3]
    TreeNode* root2 = createTree({new int(2), new int(1), new int(3)});
    TreeNode* result2 = solution.invertTree(root2);
    vector<int> expected2 = {2, 3, 1};
    RUN_TEST(treeToArray(result2), expected2, "测试用例 2: [2,1,3]");
    deleteTree(result2);
    
    // 测试用例 3: 空树
    TreeNode* root3 = nullptr;
    TreeNode* result3 = solution.invertTree(root3);
    vector<int> expected3 = {};
    RUN_TEST(treeToArray(result3), expected3, "测试用例 3: 空树");
    
    // 测试用例 4: 只有根节点
    TreeNode* root4 = new TreeNode(1);
    TreeNode* result4 = solution.invertTree(root4);
    vector<int> expected4 = {1};
    RUN_TEST(treeToArray(result4), expected4, "测试用例 4: 只有根节点");
    deleteTree(result4);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 翻转二叉树就是交换每个节点的左右子树。这是一个典型的树的递归问题。
 * 
 * 核心思路：
 * 1. 对于每个节点，交换其左右子节点
 * 2. 递归地翻转左子树和右子树
 * 3. 返回根节点
 * 
 * 【算法步骤】
 * 1. 如果根节点为空，返回 nullptr
 * 2. 交换当前节点的左右子节点
 * 3. 递归翻转左子树
 * 4. 递归翻转右子树
 * 5. 返回根节点
 * 
 * 【参考解法】
 * 
 * // 方法1：递归（DFS）
 * class Solution {
 * public:
 *     TreeNode* invertTree(TreeNode* root) {
 *         // 递归终止条件
 *         if (root == nullptr) {
 *             return nullptr;
 *         }
 *         
 *         // 交换左右子节点
 *         TreeNode* temp = root->left;
 *         root->left = root->right;
 *         root->right = temp;
 *         
 *         // 递归翻转左右子树
 *         invertTree(root->left);
 *         invertTree(root->right);
 *         
 *         return root;
 *     }
 * };
 * 
 * // 方法2：递归（更简洁的写法）
 * class Solution {
 * public:
 *     TreeNode* invertTree(TreeNode* root) {
 *         if (root == nullptr) return nullptr;
 *         
 *         // 先递归翻转左右子树，再交换
 *         TreeNode* left = invertTree(root->left);
 *         TreeNode* right = invertTree(root->right);
 *         
 *         root->left = right;
 *         root->right = left;
 *         
 *         return root;
 *     }
 * };
 * 
 * // 方法3：迭代（BFS 层序遍历）
 * class Solution {
 * public:
 *     TreeNode* invertTree(TreeNode* root) {
 *         if (root == nullptr) return nullptr;
 *         
 *         queue<TreeNode*> q;
 *         q.push(root);
 *         
 *         while (!q.empty()) {
 *             TreeNode* node = q.front();
 *             q.pop();
 *             
 *             // 交换左右子节点
 *             TreeNode* temp = node->left;
 *             node->left = node->right;
 *             node->right = temp;
 *             
 *             // 将子节点加入队列
 *             if (node->left) q.push(node->left);
 *             if (node->right) q.push(node->right);
 *         }
 *         
 *         return root;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1&2（递归）：
 * - 时间复杂度：O(n) - 需要遍历所有节点
 * - 空间复杂度：O(h) - 递归调用栈的深度，h 为树的高度
 * 
 * 方法3（迭代）：
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(w) - 队列中最多存储 w 个节点，w 为树的最大宽度
 * 
 * 【知识点】
 * - 二叉树的递归
 * - 深度优先搜索（DFS）
 * - 广度优先搜索（BFS）
 */
