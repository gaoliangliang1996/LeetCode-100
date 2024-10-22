/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 递归法
class Solution {
public:
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        
        if (root1 == nullptr || root2 == nullptr)
            return false;

        if (root1->val != root2->val)
            return false;

        return isSymmetric(root1->left, root2->right)
            && isSymmetric(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};

// 迭代法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return false;

        queue<TreeNode*> q;
        TreeNode* node = root;

        q.push(node->left);
        q.push(node->right);

        while (!q.empty()) {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();

            if (node1 == nullptr && node2 == nullptr) {
                continue;
            }

            if (node1 == nullptr || node2 == nullptr) {
                return false;
            }

            if (node1->val != node2->val) {
                return false;
            }

            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};
