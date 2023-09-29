class Solution {
public:
    int minMoves2(vector<int>& nums) {
       sort(nums.begin(),nums.end());
         int count=0;
         int len=nums.size()/2;
         for(int i=0;i<nums.size();i++){
             if(nums[i]>nums[len]){
                 int res=nums[i]-nums[len];
                 count+=res;
             }
             else if(nums[i]<nums[len]){
             int res=nums[len]-nums[i];
             count+=res;
             }
         }
         return count;

    }
};