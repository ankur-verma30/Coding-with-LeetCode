class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        if (m > n)
            return false;

        int j = 0;

        for (int i = 0; i < n; i++) {
            int val1 = str1[i] - 'a';
            int val2 = str2[j] - 'a';
            if (str1[i] == str2[j])
                j++;
            else if ((val2 - val1 + 26) % 26 == 1)
                j++;
        }

        return (j == m) ? true : false;
    }
};