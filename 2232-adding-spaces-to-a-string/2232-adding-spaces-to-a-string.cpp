class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int k = 0;
        for (int i = 0; i < s.length(); i++) {
            if (k < spaces.size() && i==spaces[k]) {
                    res += ' ';
                    k++;
                }
            res += s[i];
        }

        return res;
    }
};