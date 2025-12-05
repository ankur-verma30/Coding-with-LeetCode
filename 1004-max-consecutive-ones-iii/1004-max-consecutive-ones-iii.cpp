class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount=0, n=nums.size(), maxLen=0, left=0;

        for(int right=0; right<n; right++){
            if(nums[right]==0) zeroCount++;
            while(left<n && zeroCount>k){
                if(nums[left]==0) zeroCount--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }

        return maxLen;

    }
};