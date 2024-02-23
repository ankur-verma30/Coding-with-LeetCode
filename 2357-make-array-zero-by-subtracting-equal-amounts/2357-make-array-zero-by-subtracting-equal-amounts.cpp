class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // set<int>s;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0) s.insert(nums[i]);
        // }

        // return s.size()

        sort(nums.begin(),nums.end());
        int distinct=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0 && nums[i]!=distinct){
                count++;
                distinct=nums[i];
            }
        }
        return count;
    }
};