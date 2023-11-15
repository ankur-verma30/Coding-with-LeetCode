class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
      int multi1=nums[0]*nums[1]*nums[n-1];
       int multi2=nums[n-1]*nums[n-2]*nums[n-3];
        
        return max(multi1,multi2);
    }
};