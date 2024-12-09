class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        int count = 0;
        vector<int> parity(n, 0);

        for(int i=1;i<n;i++){
            int count = (nums[i]%2==nums[i-1]%2)?1:0;
            parity[i] = parity[i-1] + count;
        }

        vector<bool> res;
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            if((parity[right] - parity[left]) != 0) res.push_back(false);
            else res.push_back(true);
        }

        return res;
    }
};