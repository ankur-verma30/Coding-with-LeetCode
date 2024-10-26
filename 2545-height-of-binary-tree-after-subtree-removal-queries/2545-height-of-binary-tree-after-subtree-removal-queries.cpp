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
    //performing dfs from the left subtree and find the max height in left array
    void dfsFirstFromLeft(TreeNode* root, vector<int>& heightFromLeft, int d, int& maxi) {
        if (root == NULL)
            return;
        heightFromLeft[root->val] = maxi;
        maxi = max(maxi, d);
        dfsFirstFromLeft(root->left, heightFromLeft, d + 1, maxi);
        dfsFirstFromLeft(root->right, heightFromLeft, d + 1, maxi);
    }

    void dfsFirstFromRight(TreeNode* root, vector<int>& heightFromRight, int d, int& maxi) {
        if (root == NULL)
            return;
        heightFromRight[root->val] = maxi;
        maxi = max(maxi, d);
        dfsFirstFromRight(root->right, heightFromRight, d + 1, maxi);
        dfsFirstFromRight(root->left, heightFromRight, d + 1, maxi);
    }


    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
         vector<int> heightFromLeft(100001, -1), heightFromRight(100001, -1);
        int maxi = 0;
        dfsFirstFromLeft(root, heightFromLeft, 0, maxi);
        maxi = 0;
        dfsFirstFromRight(root, heightFromRight, 0, maxi);

        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int temp = max(heightFromLeft[queries[i]], heightFromRight[queries[i]]);
            res.push_back(temp);
        }
        return res;
    }
};