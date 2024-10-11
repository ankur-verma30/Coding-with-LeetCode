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
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        preorder(root->left, ans);
        ans.push_back(root->val);
        preorder(root->right, ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1, ans2;
        preorder(root1, ans1);
        preorder(root2, ans2);

        int n = ans1.size(),m = ans2.size();
        int i = 0, j = 0, k = 0;
        vector<int> res(n + m, 0);
        while (i < n && j < m) {
            if (ans1[i] < ans2[j]) {
                res[k++] = ans1[i];
                i++;
            } else {
                res[k++] = ans2[j];
                j++;
            }
        }
        while (i < n)
            res[k++] = ans1[i++];
        while (j<m)
            res[k++] = ans2[j++];


        return res;
    }
};