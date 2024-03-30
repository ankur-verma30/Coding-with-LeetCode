class Solution {
public:
    int countAtleastKDistinct(vector<int>&nums,int k){
        int count=0,size=nums.size();
       int left=0,right=0;
       unordered_map<int,int>mpp;

       
        while(right<size){
        mpp[nums[right]]++;

        while(mpp.size()>=k){
            mpp[nums[left]]--;
            if(mpp[nums[left]]==0) mpp.erase(nums[left]);
            left++;
        }
            count+=left;
            right++;
        
       } 
       return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return  (countAtleastKDistinct(nums,k)-countAtleastKDistinct(nums,k+1));
    }
};