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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> pq;
        pq.push({root, {0, 0}});

        while (!pq.empty()) {
            auto temp = pq.front();
            pq.pop();

            TreeNode* node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            nodes[x][y].insert(node->val);

            if (node->left)
                pq.push({node->left, {x - 1, y + 1}});
            if (node->right)
                pq.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        for (auto& x : nodes) {
            vector<int> col;
            for (auto& y : x.second)
                col.insert(col.end(), y.second.begin(), y.second.end());
            ans.push_back(col);
        }

        return ans;
    }
};