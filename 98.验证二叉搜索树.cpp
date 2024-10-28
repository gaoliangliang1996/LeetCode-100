// 迭代法
class Solution {
public:
    bool Core(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr)
            return true;

        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return Core(node->left, minVal, node->val) && Core(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return Core(root, LONG_MIN, LONG_MAX);
    }
};

// 中序遍历法
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* node = root;

        long pre = LONG_MIN;

        while (node != nullptr || !stack.empty()) {
            while (node != nullptr) {
                stack.push(node);
                node = node->left;
            }

            node = stack.top();
            stack.pop();

            if (node->val <= pre) {
                return false;
            }
            pre = node->val;

            node = node->right;
        }

        return true;
    }
};
