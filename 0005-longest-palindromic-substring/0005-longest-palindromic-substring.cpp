class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int count = 0, maxLen = 0;
        string ans;

        for (int i = 0; i < n; i++) {
    auto pair1 = expandFromCenter(s, i, i);       // odd length
    auto pair2 = expandFromCenter(s, i, i + 1);   // even length
    auto longest = (pair1.second > pair2.second) ? pair1 : pair2;

    if (longest.second > maxLen) {
        maxLen = longest.second;
        ans = s.substr(longest.first, maxLen);
    }
        }

        return ans;
    }

   pair<int, int> expandFromCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return {left + 1, right - left - 1};
}

};
