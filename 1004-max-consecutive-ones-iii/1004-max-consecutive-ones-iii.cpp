class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes=0,maxLength=0,length=0;
        int left=0,right=0;

        int size=nums.size();

        while(right<size){
             if(nums[right]==0) zeroes++;
             
            if(zeroes>k){  //replace while with if 
                if(nums[left]==0)  zeroes--;
                     left++;   
            }
               if(zeroes<=k){
                length=right-left+1;
                maxLength=max(maxLength,length); 
            }
              right++;  
        }
        return maxLength;
    }
};