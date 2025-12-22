/*
 * 题目编号: 107
 * 题目名称: 二叉树的层序遍历 II
 * 难度: 中等
 * 
 * 题目描述:
 * 给你二叉树的根节点 root，返回其节点值自底向上的层序遍历。
 * （即按从叶子节点所在层到根节点所在的层，逐层从左到右遍历）
 * 
 * 示例 1:
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[15,7],[9,20],[3]]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root);
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
    
    cout << "开始测试 [107. 二叉树的层序遍历 II]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [3,9,20,null,null,15,7]
    TreeNode* root1 = createTree({new int(3), new int(9), new int(20), 
                                  nullptr, nullptr, new int(15), new int(7)});
    vector<vector<int>> expected1 = {{15, 7}, {9, 20}, {3}};
    RUN_TEST(solution.levelOrderBottom(root1), expected1, "测试用例 1: [3,9,20,null,null,15,7]");
    deleteTree(root1);
    
    // 测试用例 2: [1]
    TreeNode* root2 = createTree({new int(1)});
    vector<vector<int>> expected2 = {{1}};
    RUN_TEST(solution.levelOrderBottom(root2), expected2, "测试用例 2: [1]");
    deleteTree(root2);
    
    // 测试用例 3: 空树
    TreeNode* root3 = nullptr;
    vector<vector<int>> expected3 = {};
    RUN_TEST(solution.levelOrderBottom(root3), expected3, "测试用例 3: 空树");
    
    // 测试用例 4: 只有左子树
    TreeNode* root4 = createTree({new int(1), new int(2), nullptr, new int(3)});
    vector<vector<int>> expected4 = {{3}, {2}, {1}};
    RUN_TEST(solution.levelOrderBottom(root4), expected4, "测试用例 4: 只有左子树");
    deleteTree(root4);
    
    // 测试用例 5: 完全二叉树
    TreeNode* root5 = createTree({new int(1), new int(2), new int(3), 
                                  new int(4), new int(5), new int(6), new int(7)});
    vector<vector<int>> expected5 = {{4, 5, 6, 7}, {2, 3}, {1}};
    RUN_TEST(solution.levelOrderBottom(root5), expected5, "测试用例 5: 完全二叉树");
    deleteTree(root5);
    
    // 测试用例 6: 只有右子树
    TreeNode* root6 = createTree({new int(1), nullptr, new int(2), nullptr, new int(3)});
    vector<vector<int>> expected6 = {{3}, {2}, {1}};
    RUN_TEST(solution.levelOrderBottom(root6), expected6, "测试用例 6: 只有右子树");
    deleteTree(root6);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 这道题是 LeetCode 102（二叉树的层序遍历）的变体。
 * 区别在于需要自底向上输出结果，而不是自顶向下。
 * 
 * 核心思路：
 * 1. 先进行正常的层序遍历（BFS）
 * 2. 最后将结果反转（reverse）
 * 
 * 或者：
 * 1. 在层序遍历时，将每层结果插入到结果数组的开头
 * 
 * 【算法步骤】
 * 方法1（正常遍历 + 反转）：
 * 1. 使用 BFS 进行层序遍历，得到从上到下的结果
 * 2. 使用 reverse() 函数反转结果数组
 * 3. 返回结果
 * 
 * 方法2（头部插入）：
 * 1. 使用 BFS 进行层序遍历
 * 2. 每次将当前层的结果插入到结果数组的开头
 * 3. 返回结果
 * 
 * 【参考解法】
 * 
 * // 方法1：BFS + 反转
 * class Solution {
 * public:
 *     vector<vector<int>> levelOrderBottom(TreeNode* root) {
 *         vector<vector<int>> result;
 *         if (root == nullptr) {
 *             return result;
 *         }
 *         
 *         queue<TreeNode*> q;
 *         q.push(root);
 *         
 *         while (!q.empty()) {
 *             int levelSize = q.size();
 *             vector<int> currentLevel;
 *             
 *             for (int i = 0; i < levelSize; i++) {
 *                 TreeNode* node = q.front();
 *                 q.pop();
 *                 currentLevel.push_back(node->val);
 *                 
 *                 if (node->left) q.push(node->left);
 *                 if (node->right) q.push(node->right);
 *             }
 *             
 *             result.push_back(currentLevel);
 *         }
 *         
 *         // 反转结果
 *         reverse(result.begin(), result.end());
 *         return result;
 *     }
 * };
 * 
 * // 方法2：BFS + 头部插入
 * class Solution {
 * public:
 *     vector<vector<int>> levelOrderBottom(TreeNode* root) {
 *         vector<vector<int>> result;
 *         if (root == nullptr) {
 *             return result;
 *         }
 *         
 *         queue<TreeNode*> q;
 *         q.push(root);
 *         
 *         while (!q.empty()) {
 *             int levelSize = q.size();
 *             vector<int> currentLevel;
 *             
 *             for (int i = 0; i < levelSize; i++) {
 *                 TreeNode* node = q.front();
 *                 q.pop();
 *                 currentLevel.push_back(node->val);
 *                 
 *                 if (node->left) q.push(node->left);
 *                 if (node->right) q.push(node->right);
 *             }
 *             
 *             // 插入到开头
 *             result.insert(result.begin(), currentLevel);
 *         }
 *         
 *         return result;
 *     }
 * };
 * 
 * // 方法3：DFS（递归）
 * class Solution {
 * public:
 *     vector<vector<int>> levelOrderBottom(TreeNode* root) {
 *         vector<vector<int>> result;
 *         dfs(root, 0, result);
 *         reverse(result.begin(), result.end());
 *         return result;
 *     }
 *     
 * private:
 *     void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
 *         if (node == nullptr) return;
 *         
 *         if (level >= result.size()) {
 *             result.push_back(vector<int>());
 *         }
 *         
 *         result[level].push_back(node->val);
 *         dfs(node->left, level + 1, result);
 *         dfs(node->right, level + 1, result);
 *     }
 * };
 * 
 * 【复杂度分析】
 * 方法1（BFS + 反转）：
 * - 时间复杂度：O(n) - 遍历所有节点 + 反转操作
 * - 空间复杂度：O(w) - w 是树的最大宽度
 * 
 * 方法2（BFS + 头部插入）：
 * - 时间复杂度：O(n * h) - 每层插入到开头需要 O(已有层数) 的时间
 * - 空间复杂度：O(w) - w 是树的最大宽度
 * 
 * 方法3（DFS）：
 * - 时间复杂度：O(n) - 遍历所有节点 + 反转操作
 * - 空间复杂度：O(h) - h 是树的高度（递归栈）
 * 
 * 【关键点】
 * 1. 方法1最简单直观，代码复用性好
 * 2. 方法2在每次插入时可能需要移动已有元素，效率较低
 * 3. 方法1（BFS + reverse）是最推荐的解法
 * 
 * 【对比 LeetCode 102】
 * - 102: 自顶向下的层序遍历
 * - 107: 自底向上的层序遍历（只需在 102 的基础上加一个 reverse）
 */

