/*
 * 题目编号: 102
 * 题目名称: 二叉树的层序遍历
 * 难度: 中等
 * 
 * 题目描述:
 * 给你二叉树的根节点 root，返回其节点值的层序遍历。（即逐层地，从左到右访问所有节点）。
 * 
 * 示例 1:
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * 示例 2:
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 示例 3:
 * 输入：root = []
 * 输出：[]
 * 
 * 提示:
 * - 树中节点数目在范围 [0, 2000] 内
 * - -1000 <= Node.val <= 1000
 */

/*
@Solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root);
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
    
    cout << "开始测试 [102. 二叉树的层序遍历]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [3,9,20,null,null,15,7]
    TreeNode* root1 = createTree({new int(3), new int(9), new int(20), 
                                  nullptr, nullptr, new int(15), new int(7)});
    vector<vector<int>> expected1 = {{3}, {9, 20}, {15, 7}};
    RUN_TEST(solution.levelOrder(root1), expected1, "测试用例 1: [3,9,20,null,null,15,7]");
    deleteTree(root1);
    
    // 测试用例 2: [1]
    TreeNode* root2 = createTree({new int(1)});
    vector<vector<int>> expected2 = {{1}};
    RUN_TEST(solution.levelOrder(root2), expected2, "测试用例 2: [1]");
    deleteTree(root2);
    
    // 测试用例 3: 空树
    TreeNode* root3 = nullptr;
    vector<vector<int>> expected3 = {};
    RUN_TEST(solution.levelOrder(root3), expected3, "测试用例 3: 空树");
    
    // 测试用例 4: 只有左子树
    TreeNode* root4 = createTree({new int(1), new int(2), nullptr, new int(3)});
    vector<vector<int>> expected4 = {{1}, {2}, {3}};
    RUN_TEST(solution.levelOrder(root4), expected4, "测试用例 4: 只有左子树");
    deleteTree(root4);
    
    // 测试用例 5: 完全二叉树
    TreeNode* root5 = createTree({new int(1), new int(2), new int(3), 
                                  new int(4), new int(5), new int(6), new int(7)});
    vector<vector<int>> expected5 = {{1}, {2, 3}, {4, 5, 6, 7}};
    RUN_TEST(solution.levelOrder(root5), expected5, "测试用例 5: 完全二叉树");
    deleteTree(root5);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 二叉树的层序遍历是一个经典的 BFS（广度优先搜索）问题。
 * 核心思想是使用队列来存储每一层的节点，然后逐层处理。
 * 
 * 【算法步骤】
 * 1. 如果根节点为空，直接返回空结果
 * 2. 创建一个队列，将根节点入队
 * 3. 当队列不为空时：
 *    - 记录当前队列的大小 size（即当前层的节点数）
 *    - 创建一个空数组存储当前层的节点值
 *    - 循环 size 次：
 *      * 从队列中取出一个节点
 *      * 将节点的值加入当前层数组
 *      * 如果有左子节点，将左子节点入队
 *      * 如果有右子节点，将右子节点入队
 *    - 将当前层数组加入结果中
 * 4. 返回结果
 * 
 * 【参考解法】
 * 
 * // 方法1：BFS（队列）- 标准解法
 * class Solution {
 * public:
 *     vector<vector<int>> levelOrder(TreeNode* root) {
 *         vector<vector<int>> result;
 *         if (root == nullptr) {
 *             return result;
 *         }
 *         
 *         queue<TreeNode*> q;
 *         q.push(root);
 *         
 *         while (!q.empty()) {
 *             int levelSize = q.size();  // 当前层的节点数
 *             vector<int> currentLevel;
 *             
 *             // 处理当前层的所有节点
 *             for (int i = 0; i < levelSize; i++) {
 *                 TreeNode* node = q.front();
 *                 q.pop();
 *                 currentLevel.push_back(node->val);
 *                 
 *                 // 将下一层的节点加入队列
 *                 if (node->left) q.push(node->left);
 *                 if (node->right) q.push(node->right);
 *             }
 *             
 *             result.push_back(currentLevel);
 *         }
 *         
 *         return result;
 *     }
 * };
 * 
 * // 方法2：DFS（递归）
 * class Solution {
 * public:
 *     vector<vector<int>> levelOrder(TreeNode* root) {
 *         vector<vector<int>> result;
 *         dfs(root, 0, result);
 *         return result;
 *     }
 *     
 * private:
 *     void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
 *         if (node == nullptr) return;
 *         
 *         // 如果当前层还没有数组，创建一个
 *         if (level >= result.size()) {
 *             result.push_back(vector<int>());
 *         }
 *         
 *         // 将当前节点的值加入对应层
 *         result[level].push_back(node->val);
 *         
 *         // 递归处理左右子树
 *         dfs(node->left, level + 1, result);
 *         dfs(node->right, level + 1, result);
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（BFS）：
 * - 时间复杂度：O(n) - 需要遍历所有 n 个节点
 * - 空间复杂度：O(w) - w 是树的最大宽度（队列中最多存储的节点数）
 * 
 * 方法2（DFS）：
 * - 时间复杂度：O(n) - 需要遍历所有 n 个节点
 * - 空间复杂度：O(h) - h 是树的高度（递归调用栈）
 * 
 * 【关键点】
 * 1. BFS 方法中，使用 levelSize 来确保只处理当前层的节点
 * 2. DFS 方法中，使用 level 参数来标识节点所在的层
 * 3. BFS 是最直观的层序遍历方法
 */

