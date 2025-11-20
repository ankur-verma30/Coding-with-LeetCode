class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total=(n*(n+1))/2;

        int currTotal=0;
        for(const auto num:nums) currTotal+=num;

        return total-currTotal;
    }
};