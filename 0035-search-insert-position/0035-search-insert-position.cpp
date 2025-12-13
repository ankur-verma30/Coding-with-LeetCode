class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        auto it=lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end()) return n;

        return it-nums.begin();
    
    }
};