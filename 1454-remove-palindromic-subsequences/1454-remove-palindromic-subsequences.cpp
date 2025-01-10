class Solution {
public:
    int removePalindromeSub(string s) {
        bool isPalindrome = true;
        int n = s.length(), acount = 0, bcount = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != s[n - i - 1])
                isPalindrome = false;
            if (s[i] == 'a')
                acount++;
            else
                bcount++;
        }

        if (isPalindrome)
            return 1;

        if (acount == 0 || bcount == 0)
            return 1;

        return 2;
    }
};