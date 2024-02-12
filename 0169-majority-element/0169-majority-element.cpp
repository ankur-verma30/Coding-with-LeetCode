class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];

        sort(nums.begin(),nums.end());
        int count=1,threshold=nums.size()/2;

        for(int i=1;i<nums.size();i++){
            
            if(nums[i-1]==nums[i]) count++;
            
            if(count>threshold) return nums[i];
            
            else if(nums[i]!=nums[i-1]) count=1;
        }
        return -1;
    }
};