class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,vector<vector<int>>& queries) {
        int len = nums.size();
        vector<bool> ans(queries.size(), 1);
        vector<int> prefix(len);

        for (int i = 0; i + 1 < len; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2)
                prefix[i] += 1;
            prefix[i + 1] += prefix[i];
        }

        for (int i = 0; i < queries.size(); ++i) {
            int left = queries[i][0];
            int right = queries[i][1];
            int noBadNum =
                (right ? prefix[right - 1] : 0) - (left ? prefix[left - 1] : 0);
            if (noBadNum)
                ans[i] = 0;
        }

        return ans;
    }
};