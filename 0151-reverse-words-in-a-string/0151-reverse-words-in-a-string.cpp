class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        stringstream ss1(s);
        string word;
        string res;

        while (ss1 >> word) {
            string temp = word;
            reverse(temp.begin(), temp.end());
            res += temp + " ";
        }
        res.pop_back();

        return res;
    }
};