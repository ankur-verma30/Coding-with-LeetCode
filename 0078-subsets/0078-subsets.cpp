class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len=nums.size();
        int size=1<<len;
        vector<vector<int>>powerSet(size);

      for (int i = 0; i < size; i++) {
            for (int j = 0; j < len; j++) {
                if ((i >> j) & 1) powerSet[i].push_back(nums[j]);
            }
        }
        return powerSet;
    }
};