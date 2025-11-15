class Solution {
public:
    char nthNextChar(char c, int n) {
        int index = c - 'a';
        int newIndex = (index + n) % 26;
        if (newIndex < 0)
            newIndex += 26;
        return 'a' + newIndex;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> difference(n, 0);

        for (const auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int value = (shift[2] == 0) ? -1 : 1;

            difference[start] += value;
            if (end + 1 < n)
                difference[end + 1] -= value;
        }

        for (int i = 0; i < n; i++) {
            if (i == 0)
                continue;
            difference[i] += difference[i - 1];
        }

        string str = "";
        for (int i = 0; i < n; i++) {
            char ch = nthNextChar(s[i], difference[i]);
            str += ch;
        }

        return str;
    }
};