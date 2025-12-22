/*
 * 题目编号: 094
 * 题目名称: 二叉树的中序遍历
 * 难度: 简单
 * 
 * 题目描述:
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 * 
 * 示例 1:
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 * 
 *   1
 *    \
 *     2
 *    /
 *   3
 * 
 * 示例 2:
 * 输入：root = []
 * 输出：[]
 * 
 * 示例 3:
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 提示：
 * - 树中节点数目在范围 [0, 100] 内
 * - -100 <= Node.val <= 100
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */

/*
@Solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root);
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
    
    size_t i = 1;
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
    
    cout << "开始测试 [094. 二叉树的中序遍历]..." << endl;
    cout << string(50, '-') << endl;
    
    // 测试用例 1: [1,null,2,3]
    TreeNode* root1 = createTree({new int(1), nullptr, new int(2), new int(3)});
    vector<int> expected1 = {1, 3, 2};
    RUN_TEST(solution.inorderTraversal(root1), expected1, "测试用例 1: [1,null,2,3]");
    deleteTree(root1);
    
    // 测试用例 2: 空树
    TreeNode* root2 = nullptr;
    vector<int> expected2 = {};
    RUN_TEST(solution.inorderTraversal(root2), expected2, "测试用例 2: 空树");
    
    // 测试用例 3: 单节点
    TreeNode* root3 = new TreeNode(1);
    vector<int> expected3 = {1};
    RUN_TEST(solution.inorderTraversal(root3), expected3, "测试用例 3: 单节点");
    deleteTree(root3);
    
    // 测试用例 4: 完全二叉树
    TreeNode* root4 = createTree({new int(1), new int(2), new int(3), 
                                  new int(4), new int(5)});
    vector<int> expected4 = {4, 2, 5, 1, 3};
    RUN_TEST(solution.inorderTraversal(root4), expected4, "测试用例 4: [1,2,3,4,5]");
    deleteTree(root4);
    
    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 * 
 * 【思路分析】
 * 二叉树的中序遍历是树遍历的基础，面试高频（必须掌握）。
 * 
 * 遍历顺序：**左 → 根 → 右**
 * 
 * 对于二叉搜索树（BST），中序遍历的结果是升序序列。
 * 
 * 【算法步骤】
 * 
 * 方法1：递归（最简单）
 * 1. 递归遍历左子树
 * 2. 访问根节点
 * 3. 递归遍历右子树
 * 
 * 方法2：迭代 + 栈（重要！）
 * 1. 使用栈模拟递归过程
 * 2. 先将所有左节点入栈
 * 3. 弹出栈顶，访问，再处理右子树
 * 
 * 方法3：Morris 遍历（进阶）
 * 空间复杂度 O(1)，但会临时修改树结构。
 * 
 * 【参考解法】
 * 
 * // 方法1：递归（最简单）
 * class Solution {
 * public:
 *     vector<int> inorderTraversal(TreeNode* root) {
 *         vector<int> result;
 *         inorder(root, result);
 *         return result;
 *     }
 *     
 * private:
 *     void inorder(TreeNode* root, vector<int>& result) {
 *         if (root == nullptr) return;
 *         
 *         inorder(root->left, result);   // 左
 *         result.push_back(root->val);    // 根
 *         inorder(root->right, result);   // 右
 *     }
 * };
 * 
 * // 方法2：迭代 + 栈（面试常考）
 * class Solution {
 * public:
 *     vector<int> inorderTraversal(TreeNode* root) {
 *         vector<int> result;
 *         stack<TreeNode*> stk;
 *         TreeNode* curr = root;
 *         
 *         while (curr != nullptr || !stk.empty()) {
 *             // 一直向左走，将左节点全部入栈
 *             while (curr != nullptr) {
 *                 stk.push(curr);
 *                 curr = curr->left;
 *             }
 *             
 *             // 弹出栈顶（当前子树的根）
 *             curr = stk.top();
 *             stk.pop();
 *             result.push_back(curr->val);
 *             
 *             // 转向右子树
 *             curr = curr->right;
 *         }
 *         
 *         return result;
 *     }
 * };
 * 
 * // 方法3：Morris 遍历（O(1) 空间）
 * class Solution {
 * public:
 *     vector<int> inorderTraversal(TreeNode* root) {
 *         vector<int> result;
 *         TreeNode* curr = root;
 *         
 *         while (curr != nullptr) {
 *             if (curr->left == nullptr) {
 *                 // 没有左子树，访问当前节点
 *                 result.push_back(curr->val);
 *                 curr = curr->right;
 *             } else {
 *                 // 找到左子树的最右节点
 *                 TreeNode* pred = curr->left;
 *                 while (pred->right != nullptr && pred->right != curr) {
 *                     pred = pred->right;
 *                 }
 *                 
 *                 if (pred->right == nullptr) {
 *                     // 建立线索
 *                     pred->right = curr;
 *                     curr = curr->left;
 *                 } else {
 *                     // 已有线索，访问节点并删除线索
 *                     pred->right = nullptr;
 *                     result.push_back(curr->val);
 *                     curr = curr->right;
 *                 }
 *             }
 *         }
 *         
 *         return result;
 *     }
 * };
 * 
 * 【复杂度分析】
 * 
 * 方法1（递归）：
 * - 时间复杂度：O(n) - 访问每个节点一次
 * - 空间复杂度：O(h) - 递归栈深度，h 为树高
 * 
 * 方法2（迭代）：
 * - 时间复杂度：O(n) - 访问每个节点一次
 * - 空间复杂度：O(h) - 栈的最大深度
 * 
 * 方法3（Morris）：
 * - 时间复杂度：O(n) - 每条边最多访问两次
 * - 空间复杂度：O(1) - 不使用额外空间 ⭐⭐⭐
 * 
 * 【关键点】
 * 
 * 1. **三种遍历方式对比**：
 *    - 前序遍历：根 → 左 → 右
 *    - 中序遍历：左 → 根 → 右 ⭐
 *    - 后序遍历：左 → 右 → 根
 * 
 * 2. **递归 vs 迭代**：
 *    - 递归：代码简洁，但有栈溢出风险
 *    - 迭代：代码稍复杂，但更安全
 *    - 面试中两种都要会
 * 
 * 3. **迭代的关键**：
 *    - 使用栈模拟递归
 *    - 先将所有左节点入栈
 *    - 弹出时访问，然后处理右子树
 * 
 * 4. **中序遍历的应用**：
 *    - 验证二叉搜索树（中序遍历应该是升序）
 *    - 找二叉搜索树的第 k 小元素
 *    - 二叉搜索树转有序链表
 * 
 * 【图解示例】
 * 树结构：
 *       1
 *      / \
 *     2   3
 *    / \
 *   4   5
 * 
 * 中序遍历过程：
 * 1. 先到最左节点 4
 * 2. 访问 4
 * 3. 回到 2，访问 2
 * 4. 访问 5
 * 5. 回到 1，访问 1
 * 6. 访问 3
 * 
 * 结果：[4, 2, 5, 1, 3]
 * 
 * 【面试高频程度】⭐⭐⭐⭐⭐
 * - 所有公司：基础题，必须掌握
 * - 进阶要求：能写出迭代版本
 * - 更进阶：能写出 Morris 遍历
 * 
 * 【相关题目】
 * - LeetCode 144: 二叉树的前序遍历
 * - LeetCode 145: 二叉树的后序遍历
 * - LeetCode 98: 验证二叉搜索树（利用中序遍历）
 * - LeetCode 230: 二叉搜索树中第K小的元素
 * 
 * 【面试技巧】
 * 1. 先写递归版本（简单）
 * 2. 面试官可能要求写迭代版本
 * 3. 解释清楚栈的作用和循环条件
 * 4. 如果时间充裕，可以提Morris遍历
 */

