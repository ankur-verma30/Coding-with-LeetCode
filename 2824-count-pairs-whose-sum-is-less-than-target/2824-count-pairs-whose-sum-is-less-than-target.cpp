class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
       int i=0,j=i+1,count=0;
       int len=nums.size()-1;
       sort(nums.begin(),nums.end());
       while(i!=len){
           if(nums[i]+nums[j]<target){
               count++;
               if(j!=len)
               j++;
               else
               {
                   i++;
                   j=i+1;
               }
           }
           else{
               if(j==len){
                   i++;
                   j=i+1;
               }
               else
               j++;
           }
       }
       return count;
    }
};