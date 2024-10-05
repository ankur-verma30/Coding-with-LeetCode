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
    pair<int,int>helper(TreeNode *root,int &n,int sum){
        if(root==NULL) return {0,0};
        auto [ln,ls]=helper(root->left,n,sum);
        auto [rn,rs]=helper(root->right,n,sum);
        sum=ls+rs+root->val;
        int t=ln+rn+1;
        int average=sum/t;
        if(average==root->val) n++;
        return {t,sum};
    }
    
    int averageOfSubtree(TreeNode* root) {
       if(root==NULL) return 0;
       int n=0,sum=0;
       helper(root,n,sum);
       return n;
    }
};