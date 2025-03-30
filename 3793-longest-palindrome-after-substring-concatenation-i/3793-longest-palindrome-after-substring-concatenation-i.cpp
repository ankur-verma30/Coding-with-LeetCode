class Solution {
public:
    bool isPalindrome(string& str) {
        int n = str.length();

        for (int i = 0; i < n / 2; i++) {
            if (str[i] != str[n - i - 1])
                return false;
        }

        return true;
    }

    vector<string> GenerateSubstring(string& str, int& maxLength) {
        int n = str.length();
        vector<string> subString;
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                string temp = str.substr(i, j - i );
                int len = temp.length();
                if (isPalindrome(temp))
                    maxLength = max(maxLength, len);
                subString.push_back(temp);
            }
        }
        return subString;
    }

    int longestPalindrome(string s, string t) {

        int maxLength = 0;
        vector<string> subStringOfS = GenerateSubstring(s, maxLength);
        vector<string> subStringOfT = GenerateSubstring(t, maxLength);

        int n1 = subStringOfS.size(), n2 = subStringOfT.size();

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                string temp = subStringOfS[i] + subStringOfT[j];
                int len = temp.length();
                if (isPalindrome(temp))
                    maxLength = max(maxLength, len);
            }
        }
        return maxLength;
    }
};