class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode*> q;
        queue<unsigned long long> index_q;

        q.push(root);
        index_q.push(1);

        int maxlength = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long index1 = index_q.front();
            unsigned long long index2;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                index2 = index_q.front();
                index_q.pop();

                if (node->left) {
                    q.push(node->left);
                    index_q.push(2 * index2);
                }
                if (node->right) {
                    q.push(node->right);
                    index_q.push(2 * index2 + 1);
                }
            }
            int length = index2 - index1 + 1;
            if (length > maxlength)
                maxlength = length;
        }
        return maxlength;
    }
};
