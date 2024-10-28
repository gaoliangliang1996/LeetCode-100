// 层次遍历
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        TreeNode* node = root;
        queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            int size = q.size();
            
            if (size > 0) {
                result.push_back(q.front()->val);
            }

            while (size--) {
                node = q.front();
                q.pop();

                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
        }

        return result;
    }
};
