class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;

        for (const int num : nums)
            right[num]++;

        int n = nums.size(), count = 0, mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            right[nums[i]]--;
            if (right[nums[i]] == 0)
                right.erase(nums[i]);
                
            if (left.count(nums[i] * 2)) {
                int leftCount = left[nums[i] * 2];
                int rightCount = right[nums[i] * 2];
                count=((1LL*rightCount*leftCount)+count)%mod;
            }
            left[nums[i]]++;
        }

        return count;
    }
};