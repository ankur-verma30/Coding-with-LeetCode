class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxCols = 0, row = nums.size();

        for (int i = 0; i < row; i++) {
            maxCols = max(maxCols, (int)nums[i].size());
        }

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