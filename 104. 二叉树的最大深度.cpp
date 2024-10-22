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
// 深度优先搜索
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right) ? left + 1 : right + 1;
    }
};

// 广度优先搜索
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int result = 0;

        if (root == nullptr)
            return result;
        
        TreeNode* node = root;
        deque<TreeNode*> q;
        q.push_back(node);

        while (!q.empty()) {
            int count = q.size();

            while (count--) {
                node = q.front();
                q.pop_front();

                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
            }
            result++;
        }
        return result;
    }
};
