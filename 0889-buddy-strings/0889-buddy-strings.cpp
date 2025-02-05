class Solution {
public:
    bool buddyStrings(string s1, string s2) {
         int n1 = s1.length();
        int n2 = s2.length();

        if (n1 != n2) return false;

        unordered_map<char, int> mpp1;
        int counter = 0;
        int first = -1, second = -1;

        for (int i = 0; i < n1; i++) {
            mpp1[s1[i]]++;

            if (s1[i] != s2[i]) {
                counter++;
                if (counter == 1) {
                    first = i;
                } else if (counter == 2) {
                    second = i;
                }
            }
        }

        if (counter == 2) {
            return (s1[first] == s2[second] && s1[second] == s2[first]);
        }

        if (counter == 0) {
            for (const auto &[element, freq] : mpp1) {
                if (freq > 1) return true;
            }
            return false;
        }

        return false;
    }
};