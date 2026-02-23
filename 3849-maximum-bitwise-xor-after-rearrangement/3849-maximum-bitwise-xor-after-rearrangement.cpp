class Solution {
public:
    string maximumXor(string s, string t) {
        unordered_map<char, int> mp;

        for (char ch : t) {
            mp[ch]++;
        }

        string ans = "";

        for (char ch : s) {
            if (ch == '1') {
                if (mp['0'] > 0) {
                    ans += '1';
                    mp['0']--;
                } else {
                    ans += '0';
                    mp['1']--;
                }
            } else {
                if (mp['1'] > 0) {
                    ans += '1';
                    mp['1']--;
                } else {
                    ans += '0';
                    mp['0']--;
                }
            }
        }

        return ans;
    }
};