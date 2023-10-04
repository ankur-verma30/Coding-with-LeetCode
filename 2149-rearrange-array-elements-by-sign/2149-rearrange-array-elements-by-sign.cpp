class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int> neg;
        int i=0,j=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            pos.push_back(nums[i]);
            else
            neg.push_back(nums[i]);

        }
    
     while(j<nums.size()){
         nums[j]=pos[i];
         j++;
         nums[j]=neg[i];
         i++;
         j++;
     }
     return nums;
    }
};