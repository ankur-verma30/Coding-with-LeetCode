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
    void solve(TreeNode* root, vector<vector<int>>& res, vector<int> ds,
               int sum) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            if (sum == 0)
                res.push_back(ds);
            return;
        }
        if (root->left) {
            ds.push_back(root->left->val);
            solve(root->left, res, ds, sum - root->left->val);
            ds.pop_back();
        }
        if (root->right) {
            ds.push_back(root->right->val);
            solve(root->right, res, ds, sum - root->right->val);
            ds.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> ds;
        ds.push_back(root->val);
        solve(root, res, ds, targetSum - root->val);
        return res;
    }
};