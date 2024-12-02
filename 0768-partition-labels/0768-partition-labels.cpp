class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;

        unordered_map<char, int> mpp;

        for (int i = 0; i < s.length(); i++)
            mpp[s[i]] = i;

        int prev = -1, maxi = 0;

        for (int i = 0; i < s.length(); i++) {
            maxi = max(maxi, mpp[s[i]]);
            if (maxi == i) {
                res.push_back(maxi - prev);
                prev = maxi;
            }
        }

        return res;
    }
};