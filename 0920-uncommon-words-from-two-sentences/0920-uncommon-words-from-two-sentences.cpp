class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
         unordered_map<string, int> mpp;
        string str = s1 + " " + s2;
       
        int start = 0, len = 0;

        for (int i = 0; i <= str.length(); i++) {
            if (i < str.length() && str[i] != ' ')  len++;
            else {
               
                if (len > 0) {
                    string temp = str.substr(start, len);
                    mpp[temp]++;
                }
                start = i + 1;
                len = 0;
            }
        }

        vector<string> res;

        for (auto& it : mpp) {
            if (it.second == 1) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};