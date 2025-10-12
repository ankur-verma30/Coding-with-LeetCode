class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int count=2,maxCount=0;


        for(int i=2;i<n;i++){
            if(nums[i]==nums[i-1]+nums[i-2]) count++;
            else count=2;
            maxCount=max(maxCount,count);


        }
        return maxCount;
    }
};