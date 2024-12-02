class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (const auto& num : nums)
            mpp[num]++;

        vector<vector<int>> res;

        while (true) {
            vector<int> temp;
            for (auto& [val, freq] : mpp) {
                if (freq > 0) {
                    temp.push_back(val);
                    freq--;
                }
            }
            if (temp.empty())
                break;
            res.push_back(temp);
        }

        return res;
    }
};