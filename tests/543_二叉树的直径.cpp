/*
 * 题目编号: 543
 * 题目名称: 二叉树的直径
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
 * 这条路径可能穿过也可能不穿过根结点。
 * 
 * 注意: 两结点之间的路径长度是以它们之间边的数目表示。
 * 
 * 示例:
 * 给定二叉树
 * 
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * 
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 * 
 * 提示:
 * - 树中节点数目在范围 [1, 10^4] 内
 * - -100 <= Node.val <= 100
 */

/*
@Solution
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root);
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

// 辅助函数：删除树
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;
    
    cout << "开始测试 [543. 二叉树的直径]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [1,2,3,4,5]
    TreeNode* root1 = createTree({new int(1), new int(2), new int(3), 
                                  new int(4), new int(5)});
    RUN_TEST(solution.diameterOfBinaryTree(root1), 3, 
             "测试用例 1: [1,2,3,4,5]");
    deleteTree(root1);
    
    // 测试用例 2: [1,2]
    TreeNode* root2 = createTree({new int(1), new int(2)});
    RUN_TEST(solution.diameterOfBinaryTree(root2), 1, 
             "测试用例 2: [1,2]");
    deleteTree(root2);
    
    // 测试用例 3: 只有根节点
    TreeNode* root3 = new TreeNode(1);
    RUN_TEST(solution.diameterOfBinaryTree(root3), 0, 
             "测试用例 3: [1] (只有根节点)");
    deleteTree(root3);
    
    // 测试用例 4: 完全二叉树
    TreeNode* root4 = createTree({new int(1), new int(2), new int(3), 
                                  new int(4), new int(5), new int(6), new int(7)});
    RUN_TEST(solution.diameterOfBinaryTree(root4), 4, 
             "测试用例 4: 完全二叉树");
    deleteTree(root4);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 二叉树的直径是任意两个节点之间路径长度的最大值。这条路径可能经过根节点，也可能不经过。
 * 
 * 核心思路：
 * 1. 对于每个节点，经过该节点的最长路径 = 左子树深度 + 右子树深度
 * 2. 树的直径 = 所有节点的"左子树深度 + 右子树深度"的最大值
 * 3. 使用递归计算每个节点的深度，同时更新最大直径
 * 
 * 【算法步骤】
 * 1. 定义一个全局变量或成员变量记录最大直径
 * 2. 递归计算每个节点的深度：
 *    - 如果节点为空，深度为 0
 *    - 递归计算左子树深度和右子树深度
 *    - 更新最大直径 = max(最大直径, 左深度 + 右深度)
 *    - 返回当前节点的深度 = max(左深度, 右深度) + 1
 * 3. 返回最大直径
 * 
 * 【参考解法】
 * 
 * // 方法1：深度优先搜索（DFS）
 * class Solution {
 * private:
 *     int maxDiameter = 0;
 *     
 *     int depth(TreeNode* node) {
 *         if (node == nullptr) {
 *             return 0;
 *         }
 *         
 *         // 递归计算左右子树的深度
 *         int leftDepth = depth(node->left);
 *         int rightDepth = depth(node->right);
 *         
 *         // 更新最大直径
 *         // 经过当前节点的路径长度 = 左子树深度 + 右子树深度
 *         maxDiameter = max(maxDiameter, leftDepth + rightDepth);
 *         
 *         // 返回当前节点的深度
 *         return max(leftDepth, rightDepth) + 1;
 *     }
 *     
 * public:
 *     int diameterOfBinaryTree(TreeNode* root) {
 *         maxDiameter = 0;
 *         depth(root);
 *         return maxDiameter;
 *     }
 * };
 * 
 * // 方法2：使用引用传递最大直径
 * class Solution {
 * public:
 *     int diameterOfBinaryTree(TreeNode* root) {
 *         int diameter = 0;
 *         depth(root, diameter);
 *         return diameter;
 *     }
 *     
 * private:
 *     int depth(TreeNode* node, int& diameter) {
 *         if (node == nullptr) {
 *             return 0;
 *         }
 *         
 *         int leftDepth = depth(node->left, diameter);
 *         int rightDepth = depth(node->right, diameter);
 *         
 *         // 更新直径
 *         diameter = max(diameter, leftDepth + rightDepth);
 *         
 *         return max(leftDepth, rightDepth) + 1;
 *     }
 * };
 * 
 * 【复杂度分析】
 * - 时间复杂度：O(n) - 需要遍历所有节点一次
 * - 空间复杂度：O(h) - 递归调用栈的深度，h 为树的高度
 *   - 最好情况（平衡树）：O(log n)
 *   - 最坏情况（链状树）：O(n)
 * 
 * 【知识点】
 * - 二叉树的深度优先搜索（DFS）
 * - 递归思想
 * - 树的深度和直径的关系
 * - 后序遍历（左右根）
 * 
 * 【关键理解】
 * 1. 直径不一定经过根节点
 * 2. 经过某个节点的最长路径 = 该节点的左子树深度 + 右子树深度
 * 3. 树的直径 = 所有节点的"左子树深度 + 右子树深度"中的最大值
 * 4. 在计算深度的同时更新最大直径，避免重复遍历
 * 
 * 【易错点】
 * - 容易误以为直径一定经过根节点
 * - 深度和直径的区别：深度是从根到叶子的边数，直径是任意两点间的最长路径
 * - 路径长度是边的数量，不是节点的数量
 */
