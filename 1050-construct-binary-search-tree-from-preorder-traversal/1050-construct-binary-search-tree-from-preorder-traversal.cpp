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
    TreeNode* Build(vector<int>& preorder, int& pos, int bound) {
        if (pos == preorder.size() || preorder[pos] > bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pos++]);
        root->left = Build(preorder, pos, root->val);
        root->right = Build(preorder, pos, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return Build(preorder, i, INT_MAX);
    }
};