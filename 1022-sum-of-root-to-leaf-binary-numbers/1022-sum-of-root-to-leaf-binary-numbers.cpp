class Solution {
public:
    int binaryToDecimal(const string &binary) {
        int decimal = 0;
        int length = binary.length();

        for (int i = 0; i < length; ++i) {
            if (binary[i] == '1') {
                decimal += (1 << (length - i - 1));  // better than pow
            }
        }
        return decimal;
    }

    void solve(TreeNode *root, int &sum, string &str) {
        if (!root) return;
        str.push_back(root->val + '0');

        // If leaf node, convert and add
        if (!root->left && !root->right) {
            sum += binaryToDecimal(str);
        } else {
            solve(root->left, sum, str);
            solve(root->right, sum, str);
        }
        str.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        string str = "";
        solve(root, sum, str);
        return sum;
    }
};