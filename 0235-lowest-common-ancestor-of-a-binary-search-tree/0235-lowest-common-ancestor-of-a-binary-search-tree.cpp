/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        int first = p->val;
        int second = q->val;
        int val = root->val;
        if (val < first && val < second)
            return lowestCommonAncestor(root->right, p, q);
        else if (val > first && val > second)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};