class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        // T.C: O(n) S.C: O(1)
        int n = nums.size();
        long long result = 0, maxi = 0, maxDiff = 0;

        for (int i = 0; i < n; i++) {
            result = max(result, maxDiff * nums[i]);
            maxDiff = max(maxDiff, maxi - nums[i]);
            maxi = max(maxi, (long long)nums[i]);
        }

        return result;
    }
};