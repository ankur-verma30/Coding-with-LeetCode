class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> mpp;

        for (const auto &response : responses) {
            set<string> st(response.begin(), response.end());
            for (const auto &it : st) {
                mpp[it]++;
            }
        }

        int maxFreq = 0;
        string ans;

        for (const auto &[response, freq] : mpp) {
            if (freq > maxFreq || (freq == maxFreq && response < ans)) {
                maxFreq = freq;
                ans = response;
            }
        }

        return ans;
    }
};