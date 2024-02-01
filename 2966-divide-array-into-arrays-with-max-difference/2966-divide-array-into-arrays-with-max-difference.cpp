class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        vector<int> mid;
        for (int i = 0; i < nums.size(); i = i + 3) {
            if ((nums[i + 2] - nums[i]) <= k) {
                mid = {nums[i], nums[i + 1], nums[i + 2]};
                ans.push_back(mid);
            } else
                return {};
        }
        return ans;
    }
};