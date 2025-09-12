class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n=nums.size();

        sort(nums.rbegin(),nums.rend());

        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            ans=min(ans,(nums[i]-nums[i+1]));
        }

        return ans;
    }
};