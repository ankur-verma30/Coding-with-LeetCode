class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
int i =0;
       
        for(auto value: nums)
            if(i==0 || i==1 || nums[i-2] != value)
            {
                nums[i] = value;
                i++;
            }
    return i ;
    }
        
    
};