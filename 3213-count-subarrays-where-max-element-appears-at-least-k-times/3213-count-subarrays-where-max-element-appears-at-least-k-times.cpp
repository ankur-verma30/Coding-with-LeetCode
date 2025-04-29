class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement=0,left=0,right=0;
        long long int maxCount=0;
        int size=nums.size(),count=0;

        for(int i=0;i<size;i++){
            if(nums[i]>maxElement) maxElement=nums[i];
        }

        while(right<size){
            if(nums[right]==maxElement) count++;

            while(count>=k){
                maxCount+=(size-right);
                if(nums[left]==maxElement) count--;
                left++;
            }
             right++;
        }

        return maxCount;
    }
};