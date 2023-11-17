class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int mx=0;

        sort(nums.begin(),nums.end());

        int low=0;
        int high=nums.size()-1;

        while(low<high){
            mx=max(mx,(nums[low]+nums[high]));
            low++;
            high--;
        }
        return mx;
    }
};