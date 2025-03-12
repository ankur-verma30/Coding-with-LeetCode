class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int row = nums.size();

      
        map < int, vector<int>> mpp;
         for (int r = row-1; r >= 0; r--) {
            for (int col = 0; col < nums[r].size(); col++) {
                int diagonal = r + col;
                mpp[diagonal].push_back(nums[r][col]);
            }
        }

        vector<int> ans;
        int curr=0;
        while (mpp.find(curr)!=mpp.end()) {
            vector<int>num=mpp[curr];
            ans.insert(ans.end(),num.begin(),num.end());
            curr++;
        }

        return ans;
    }
};