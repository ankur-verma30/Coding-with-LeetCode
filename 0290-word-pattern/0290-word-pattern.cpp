class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> mpp;
        unordered_map<char, string> mpp2;
        int count = 0;
        int i = 0, j = 0;

        stringstream ss(s);
        string word;

        while (ss >> word) {
            if (j >= pattern.length())
                return false;
            char ch = pattern[j++];

            if (mpp.find(word) != mpp.end()) {
                if (mpp[word] != ch)
                    return false;
            } else
                mpp[word] = ch;

            if (mpp2.find(ch) != mpp2.end()) {
                if (mpp2[ch] != word)
                    return false;
            }
            mpp2[ch] = word;
        }

        return (j == pattern.length());
    }
};