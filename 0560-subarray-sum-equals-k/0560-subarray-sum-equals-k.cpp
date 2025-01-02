class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0, count = 0;
        unordered_map<int, int> prefixFreq;

        prefixFreq[0] = 1;

        for (const auto num : nums) {
            prefixSum += num;
            int remove = prefixSum - k;
            count += prefixFreq[remove];
            prefixFreq[prefixSum]++;
        }

        return count;
    }
};