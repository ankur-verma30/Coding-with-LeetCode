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
    int countSwaps(vector<int>& levelElements) {
        int n = levelElements.size();
        int count = 0;
        vector<int> target(levelElements.begin(),levelElements.end());
        sort(target.begin(), target.end());

        unordered_map<int, int> position;

        for (int i = 0; i < n; i++) {
            position[levelElements[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (levelElements[i] != target[i])
                count++;
            int currPosition = position[target[i]];
            position[levelElements[i]] = currPosition;
            swap(levelElements[currPosition], levelElements[i]);
        }

        return count;
    }

public:
    int minimumOperations(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int operations = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<int> levelElements;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                levelElements.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

            }
            operations += countSwaps(levelElements);
        }

        return operations;
    }
};