/*
 * 题目编号: 101
 * 题目名称: 对称二叉树
 * 难度: 简单
 *
 * 题目描述:
 * 给你一个二叉树的根节点 root ，检查它是否轴对称。
 *
 * 示例 1:
 * 输入: root = [1,2,2,3,4,4,3]
 * 输出: true
 *
 * 示例 2:
 * 输入: root = [1,2,2,null,3,null,3]
 * 输出: false
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

/*
@Solution
class Solution {
public:
    bool isSymmetric(TreeNode* root);
};
@EndSolution
*/

#include "../template.cpp"

// ==================== 辅助函数 ====================

TreeNode* createTree(const vector<int*>& values) {
    if (values.empty() || values[0] == nullptr) return nullptr;

    TreeNode* root = new TreeNode(*values[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
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

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ==================== 测试代码 ====================

int main() {
    Solution solution;

    cout << "开始测试 [101. 对称二叉树]..." << endl;
    cout << string(50, '-') << endl;

    TreeNode* t1 = createTree({new int(1), new int(2), new int(2), new int(3), new int(4), new int(4), new int(3)});
    RUN_TEST(solution.isSymmetric(t1), true, "测试用例 1: [1,2,2,3,4,4,3]");
    deleteTree(t1);

    TreeNode* t2 = createTree({new int(1), new int(2), new int(2), nullptr, new int(3), nullptr, new int(3)});
    RUN_TEST(solution.isSymmetric(t2), false, "测试用例 2: [1,2,2,null,3,null,3]");
    deleteTree(t2);

    TreeNode* t3 = nullptr;
    RUN_TEST(solution.isSymmetric(t3), true, "测试用例 3: 空树");

    TreeNode* t4 = new TreeNode(1);
    RUN_TEST(solution.isSymmetric(t4), true, "测试用例 4: 单节点");
    deleteTree(t4);

    TEST_SUMMARY();
    return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【核心】递归判断“镜像相等”
 * 判断两棵树是否互为镜像：left 的左 vs right 的右，left 的右 vs right 的左。
 *
 * mirror(a, b):
 * - a 和 b 都为空 -> true
 * - 一个为空 -> false
 * - a->val != b->val -> false
 * - mirror(a->left, b->right) && mirror(a->right, b->left)
 *
 * 【常用点】
 * - 递归函数写成私有 helper
 * - 也可用队列做迭代（成对入队）
 *
 * 【参考解法】
 * class Solution {
 * public:
 *     bool isSymmetric(TreeNode* root) {
 *         return mirror(root, root);
 *     }
 * private:
 *     bool mirror(TreeNode* a, TreeNode* b) {
 *         if (a == nullptr && b == nullptr) return true;
 *         if (a == nullptr || b == nullptr) return false;
 *         if (a->val != b->val) return false;
 *         return mirror(a->left, b->right) && mirror(a->right, b->left);
 *     }
 * };
 *
 * 【复杂度】
 * - 时间：O(n)
 * - 空间：O(h)（递归栈）
 */

