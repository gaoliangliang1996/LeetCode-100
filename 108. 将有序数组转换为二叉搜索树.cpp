// 在二叉搜索树中：
// 1.若任意结点的左子树不空，则左子树上所有结点的值均不大于它的根结点的值。
// 2.若任意结点的右子树不空，则右子树上所有结点的值均不小于它的根结点的值。
// 3.任意结点的左、右子树也分别为二叉搜索树。

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
    TreeNode* Core(vector<int> &nums, int left, int right) {
        if (left > right)
            return nullptr;
        
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = Core(nums, left, mid - 1);
        node->right = Core(nums, mid + 1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Core(nums, 0, nums.size() - 1);
    }
};
