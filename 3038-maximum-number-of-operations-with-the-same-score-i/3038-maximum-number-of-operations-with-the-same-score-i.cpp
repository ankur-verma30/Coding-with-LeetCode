class Solution {
public:
    int maxOperations(vector<int>& nums) {
        if(nums.size()<2) return 0;
        if(nums.size()==2) return 1;
         
        int count=1;
        int maxi=nums[0]+nums[1];
        
        for(int i=2;i<nums.size();i=i+2){
            
             if(nums[i]+nums[i+1]==maxi) count++;
            
            else if(nums.size()-i-1==0) break;
            else break;
        }
        
        return count;
    }
};