class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mpp;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            string curString;
            for (int j = i; j < n; j++) {
                if (curString.length() == 0 ||
                    s[j] == curString[curString.length() - 1]) {
                    curString += s[j];
                    mpp[curString]++;
                } else
                    break;
            }
        }

        int maxLen = -1;
        for (const auto &[val, freq]:mpp) {
            if (freq > 2)
                maxLen = max(maxLen,(int)val.length());
        }
        return maxLen;
    }
};