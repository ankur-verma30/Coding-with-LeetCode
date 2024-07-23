class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (auto& num : nums)
            freq[num]++;

        vector<int> res(nums);

        sort(res.begin(), res.end(), [&freq](int a, int b) {
            if (freq[a] == freq[b])
                return a > b;
            return freq[a] < freq[b];
        });

        return res;
    }
};