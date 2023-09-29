class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
         int max = *max_element(nums.begin(),nums.end());
        int min = *min_element(nums.begin(),nums.end());
        for(int result: nums){
            if(result!=max && result!=min)
             return result;
        }
        return -1;
    }
};