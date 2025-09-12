class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int ans=INT_MAX;
        for(int i=n-1;i>=1;i--){
            ans=min(ans,(nums[i]-nums[i-1]));
        }

        return ans;
    }
};