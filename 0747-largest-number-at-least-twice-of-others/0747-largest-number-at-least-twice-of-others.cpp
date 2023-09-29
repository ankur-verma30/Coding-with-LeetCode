class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int maxi=0,pos=0;
           for(int i=0;i<nums.size();i++)
           {
            if(nums[i]>maxi)
            {
            maxi=nums[i];
            pos=i;    
            }
           }    
        for (int i = 0; i < nums.size(); i++) 
        if (i != pos && nums[i] * 2 > maxi) 
            return -1;
    return pos;     
    }
};