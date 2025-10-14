class Solution {
public:
    bool isIncreasing(vector<int>&nums,int startingIndex,int length){
        int n=nums.size();
        if(startingIndex+length>n) return false;
        int curr=nums[startingIndex];
        for(int i=startingIndex+1;i<startingIndex+length;i++){
            if(curr>=nums[i]) return false;
            else curr=nums[i];
        }

        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2*k) return false;


        for(int i=0;i<n-k;i++){
            bool inc1=false,inc2=false;
            if(isIncreasing(nums,i,k) && isIncreasing(nums,i+k,k)) return true;
        }

        return false;
    }
};