// 递归法
class Solution {
public:
    void Core(TreeNode* node, vector<int>& res) {
        if (node == nullptr)
            return;

        res.push_back(node->val);
        Core(node->left, res);
        Core(node->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        Core(root, result);
        return result;
    }
};

// 迭代法，使用stack容器，先压右子节点、再压左子节点
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;

        stack<TreeNode*> stack;
        TreeNode* node = root;
        stack.push(node);

        while (!stack.empty()) {
            node = stack.top();
            stack.pop();
            result.push_back(node->val);

            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
        }
        return result;
    }
};
