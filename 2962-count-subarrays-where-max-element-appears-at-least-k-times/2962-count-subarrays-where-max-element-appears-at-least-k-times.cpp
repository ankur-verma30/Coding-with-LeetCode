class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement=0,left=0,right=0;
        long long int maxCount=0;
        int size=nums.size();
        unordered_map<int,int>mp;

        //finding the maxElement in the array
        for(int i=0;i<size;i++){
            if(nums[i]>maxElement) maxElement=nums[i];
        }

        //for using sliding window  and two pointer approach
        while(right<size){

            if(nums[right]==maxElement) mp[maxElement]++;

            //when count is greater than k
            while(mp[maxElement]>=k){
                maxCount+=(size-right);
                if(nums[left]==maxElement) mp[maxElement]--;
                left++;
            }
             right++;
        }

        return maxCount;
    }
};