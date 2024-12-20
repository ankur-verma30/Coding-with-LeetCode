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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL)
            return root;

        queue<TreeNode*> q;

        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> elements;

            for (int i = 0; i < size; i++) {
                 TreeNode* node = q.front();
                 q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                if (level % 2 != 0)
                    elements.push_back(node);
            }

            if (level % 2 != 0) {
                int left = 0, right = elements.size() - 1;
                while (right > left) {
                    swap(elements[left]->val, elements[right]->val);
                    right--;
                    left++;
                }
            }

            level++;
        }

        return root;
    }
};