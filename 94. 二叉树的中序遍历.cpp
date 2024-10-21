class Solution {
public:
    void inorder(TreeNode* root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* node = root;

        while (node != nullptr || !stack.empty()) {
            while (node != nullptr) {
                stack.push(node);
                node = node->left;
            }

            node = stack.top();
            stack.pop();
            result.push_back(node->val);
            node = node->right;
        }

        return result;
    }
};
