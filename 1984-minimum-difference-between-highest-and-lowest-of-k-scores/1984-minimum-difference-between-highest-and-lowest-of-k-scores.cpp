class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if (k == 1)
            return 0;

        int diff = INT_MAX,left=0;

        for(int right=0;right<n;right++){
            if(right-left+1>k) left++;
            if(right-left+1==k){
                diff=min(diff,nums[right]-nums[left]);
            }
        }

        return diff;
    }
};