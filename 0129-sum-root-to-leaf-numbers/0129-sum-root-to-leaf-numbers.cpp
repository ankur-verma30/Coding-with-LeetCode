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
    void helper(TreeNode* root, int& sum, int temp) {
        if (root == NULL)
            return;
        temp = temp * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            sum += temp;
        helper(root->left, sum, temp);
        helper(root->right, sum, temp);
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int sum = 0;
        helper(root, sum, 0);
        return sum;
    }
};