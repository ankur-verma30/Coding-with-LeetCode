class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string res;
        int n = target.length();

        for (char ch : target) {
            for (char temp = 'a'; temp <= ch; temp++) {
                ans.push_back(res + temp);
            }
            res += ch;
        }

        return ans;
    }
};