class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string str = "";
        vector<string> ans;
        for (const auto& ch : s) {
            str += ch;
            if (str.size() == k) {
                ans.push_back(str);
                str = "";
            }
        }

        while (str.size() != k && !str.empty())
            str.push_back(fill);
        if (!str.empty())
            ans.push_back(str);
        return ans;
    }
};