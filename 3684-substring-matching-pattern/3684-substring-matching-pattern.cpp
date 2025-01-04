class Solution {
public:
    bool hasMatch(string s, string p) {

        int starIndex = p.find('*');
        string word1 = p.substr(0, starIndex);
        string word2 = p.substr(starIndex + 1);

        int len1 = s.find(word1);
        int len2 = s.rfind(word2);
        return len1 != -1 && len2 != -1 && len1 + word1.size() <= len2;
    }
};