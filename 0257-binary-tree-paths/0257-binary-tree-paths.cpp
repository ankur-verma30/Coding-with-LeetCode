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
    void GetAllPath(TreeNode* root, vector<string>& res, string ans) {
        if (!root)
            return;

        ans += to_string(root->val) + "->";
        if (!root->left && !root->right) {
            ans.pop_back();
            ans.pop_back();
            res.push_back(ans);
        }

        GetAllPath(root->left, res, ans);
        GetAllPath(root->right, res, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string ans = "";
        if (root == NULL)
            return res;
        GetAllPath(root, res, ans);

        return res;
    }
};