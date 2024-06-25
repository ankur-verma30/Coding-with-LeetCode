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
    void InorderTraversal(TreeNode* root, vector<int>& values) {
        if (root == nullptr)
            return;
        InorderTraversal(root->left, values);
        values.push_back(root->val);
        InorderTraversal(root->right, values);
    }

    TreeNode* bstToGst(TreeNode* root) {
        vector<int> values;
        InorderTraversal(root, values);

        unordered_map<int, int> sumMap;
        int total = 0;

        for (int i = values.size() - 1; i >= 0; --i) {
            total += values[i];
            sumMap[values[i]] = total;
        }

        updateTree(root, sumMap);

        return root;
    }
    void updateTree(TreeNode* root, unordered_map<int, int>& sumMap) {
        if (root == nullptr)
            return;
        root->val = sumMap[root->val];
        updateTree(root->left, sumMap);
        updateTree(root->right, sumMap);
    }
};