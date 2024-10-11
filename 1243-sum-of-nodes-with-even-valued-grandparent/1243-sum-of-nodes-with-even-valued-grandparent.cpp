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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->val % 2 == 0) {
                TreeNode *ptr1 = curr->left, *ptr2 = curr->right;
                if (ptr1) {
                    if (ptr1->left)
                        sum += ptr1->left->val;
                    if (ptr1->right)
                        sum += ptr1->right->val;
                }
                if (ptr2) {
                    if (ptr2->left)
                        sum += ptr2->left->val;
                    if (ptr2->right)
                        sum += ptr2->right->val;
                }
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        return sum;
    }
};