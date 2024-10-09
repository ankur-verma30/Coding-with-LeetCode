/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>res;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            long long temp=0;
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                temp+=curr->val;
            }
            res.push_back(temp);
        }

        if(res.size()<k) return -1;
        sort(res.begin(),res.end(),greater());
        return res[k-1];

    }
};