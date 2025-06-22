class Solution {
public:
    int CombinationSum(vector<int>&ans,int target){
        vector<int> dp(target + 1, 0);
        dp[0] = 1; 

        for (int it : ans) {
            for (int sum = it; sum <= target; sum++) {
            dp[sum] += dp[sum - it];
            }
        }

    return dp[target];
    }
    vector<int> findCoins(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(ans.empty() && nums[i]==1){
                ans.push_back(i+1);
                continue;
            }
            int ways=CombinationSum(ans,i+1);
            if(ways+1==nums[i]) ans.push_back(i+1);
            else if(ways==nums[i]) continue;
            else if(ways+1!=nums[i]){
                ans.clear();
                return ans;
            }
        }


        return ans;
    }
};