class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        int n = nums.size();
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());

            for (int i = n - 1; i >= 0 && k--; i--) mpp[temp[i]]++;

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mpp.find(nums[i]) != mpp.end()) {
                ans.push_back(nums[i]);
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)
                    mpp.erase(nums[i]);
            }
        }

        return ans;
    }
};