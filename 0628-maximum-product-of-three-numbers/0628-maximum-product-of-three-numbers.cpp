class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int multi1=0,multi2=0;
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        multi1=nums[0]*nums[1]*nums[n-1];
        multi2=nums[n-1]*nums[n-2]*nums[n-3];
        
        return max(multi1,multi2);
    }
};