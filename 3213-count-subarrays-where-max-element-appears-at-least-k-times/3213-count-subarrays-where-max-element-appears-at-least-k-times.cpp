class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int left=0,right=0;
        long long int maxCount=0;
        int size=nums.size(),count=0;

        auto maxElement=*max_element(nums.begin(),nums.end());
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