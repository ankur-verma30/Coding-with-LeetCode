class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
       int len=nums.size();
       int mx=0;

       sort(nums.begin(),nums.end());

        for(int i=len-1;i>=2;i--){
            if(nums[i]<(nums[i-1]+nums[i-2]))
            mx=max(mx,(nums[i]+nums[i-1]+nums[i-2]));
        }

        return mx;

       
    }
};