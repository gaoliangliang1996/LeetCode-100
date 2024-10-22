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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            vector<int> vec;
            int count = q.size();

            while (count--) {
                TreeNode* node = q.front();
                q.pop_front();

                vec.push_back(node->val);

                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
            }

            result.push_back(vec);
        }
        return result;
    }
};
