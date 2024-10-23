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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        vector<int> sum;
        while (!q.empty()) {
            int total = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                total += curr->val;
            }
            sum.push_back(total);
        }

        // pass 2 of BFS
        int level = 0;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int total = 0;
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left)
                    total += curr -> left->val;
                if (curr->right)
                    total += curr->right->val;

                if (curr->left) {
                    curr->left->val = sum[level + 1] - total;
                    q.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = sum[level + 1] - total;
                    q.push(curr->right);
                }
            }
            level++;
        }
        root->val = 0;
        return root;
    }
};