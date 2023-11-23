class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int len=nums.size(),sum=0,leftSum=0;

        for(auto x:nums)
        sum+=x;

        for(int i=0;i<len;i++)
        {
            if(leftSum==sum-nums[i])
            return i;
            leftSum+=nums[i];
            sum-=nums[i];
        }
        return -1;

    
    }
};