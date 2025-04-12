class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total=0;

        for(const auto it:nums) total+=it;

        return total%k;
    }
};