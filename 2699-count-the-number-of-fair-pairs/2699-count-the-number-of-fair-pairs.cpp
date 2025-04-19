class Solution {
public:
    long long pairsWithSumLessThanSum(vector<int> nums, int val) {
        int end = nums.size() - 1;
        long long count = 0;
        for (int start = 0; start < end; start++) {
            while (end > start && nums[start] + nums[end] >= val)
                end--;
            count += end - start;
        }
        return count;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return pairsWithSumLessThanSum(nums, upper + 1) -
               pairsWithSumLessThanSum(nums, lower);
    }
};