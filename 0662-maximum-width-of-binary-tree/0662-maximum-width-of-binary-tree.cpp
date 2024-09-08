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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, long long>> pq;
        pq.push({root, 0});

        long long ans = 0;

        while (!pq.empty()) {
            long long size = pq.size();
            long long mini = pq.front().second;
            long long first, last;
            for (long long i = 0; i < size; i++) {
                long long curr_id = pq.front().second - mini;
                TreeNode* temp = pq.front().first;
                pq.pop();
                if (i == 0)
                    first = curr_id;
                if (i == size - 1)
                    last = curr_id;
                if (temp->left)
                    pq.push({temp->left, curr_id * 2 + 1});
                if (temp->right)
                    pq.push({temp->right, curr_id * 2 + 2});
            }

            ans = max(ans, (last - first + 1));
        }

        return ans;
    }
};