class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,sum=0,maxSum=0,n=nums.size(),minLen=n;

        for(int right=0;right<n;right++){
            sum+=nums[right];
            if(sum>=target){
                maxSum=max(sum,maxSum);
                minLen=min(minLen,right-left+1);
                while(left<n && sum>=target){
                    minLen=min(minLen,right-left+1);
                    sum-=nums[left++];
                }
            }
        }
        if(maxSum<target) return 0;
        return minLen;
    }
};