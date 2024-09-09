/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent_track,
                    TreeNode* target) {
        queue<TreeNode*> pq;
        pq.push(root);
        while (!pq.empty()) {
            TreeNode* current = pq.front();
            pq.pop();
            if (current->left) {
                parent_track[current->left] = current;
                pq.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                pq.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track, target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> pq;
        pq.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!pq.empty()) {
            int size = pq.size();
            if (curr_level++ == k)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* current = pq.front();
                pq.pop();
                if (current->left && !visited[current->left]) {
                    pq.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    pq.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    pq.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            int val=pq.front()->val;
            res.push_back(val);
            pq.pop();
        }

        return res;
    }
};