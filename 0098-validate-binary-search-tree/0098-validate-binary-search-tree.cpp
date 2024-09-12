/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidate(TreeNode* root, long long minval, long long maxval) {
        if (root == NULL)
            return true;
        if (root->val <= minval || root->val >= maxval)
            return false;
        return isValidate(root->left, minval, root->val) &&
               isValidate(root->right, root->val, maxval);
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        return isValidate(root, LONG_MIN, LONG_MAX);
    }
};