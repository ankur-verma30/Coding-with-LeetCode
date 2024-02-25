class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        
       sort(nums.begin(),nums.end());
        int count=1,maxCount=1;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
                maxCount=max(count,maxCount);
            }
            else count=1;
            
        }
        
        return (maxCount<=2)?true:false;
    }
};