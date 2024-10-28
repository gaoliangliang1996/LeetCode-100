// 和 144.二叉树的前序遍历 很像。需要先做144题目
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        
        TreeNode* node = root;
        TreeNode* pre = nullptr;
        stack<TreeNode*> stack;
        stack.push(node);

        while (!stack.empty()) {
            node = stack.top();
            stack.pop();

            if (pre) {
                pre->left = nullptr;
                pre->right = node;
            }
            pre = node;

            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
        }

    }
};
