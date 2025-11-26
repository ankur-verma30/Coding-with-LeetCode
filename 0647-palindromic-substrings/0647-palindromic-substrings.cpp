class Solution {
public:
    bool checkPalindrome(int start, int end, string& s) {
        if (start >= end)
            return true;
        if (s[start] != s[end]) return false;
        return checkPalindrome(start + 1, end - 1, s);

    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPalindrome(i, j, s))
                    count++;
            }
        }

        return count;
    }
};