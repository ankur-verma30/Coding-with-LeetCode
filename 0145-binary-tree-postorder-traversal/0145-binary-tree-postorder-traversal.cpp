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
 vector<int> ans;
    void Postorder(TreeNode* root){ 
        if(root->left) Postorder(root->left);
        if(root->right) Postorder(root->right);
         ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        Postorder(root);
        return ans;

    }
};