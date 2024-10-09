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
    string tree2str(TreeNode* root) {
      string LeftString="",RightString="";
      if(root->right) RightString='('+tree2str(root->right)+')';
      if(root->left) LeftString='('+tree2str(root->left)+')';
    else if(root->right) LeftString="()";
    return to_string(root->val)+LeftString+RightString;
    }
};