class Solution {
public:
    int countSumEqualToK(vector<int>&nums,int k){
        if(k<0) return 0;
        int left=0,right=0,count=0,sum=0;

        int size=nums.size();

        while(right<size){
            sum+=(nums[right]%2);

            while(sum>k){
                sum-=(nums[left]%2);
                left++;
            }
             count+=right-left+1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (countSumEqualToK(nums,k)-countSumEqualToK(nums,k-1));
    }
};