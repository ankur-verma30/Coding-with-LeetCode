class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int n = s.size();
        multiset<char> chs;

        for (char x : s)
            chs.insert(x);

        vector<string> ans;
        string prefix = "";

        for (int i = 0; i < n; i++) {
            auto it = chs.upper_bound(t[i]);
            if (it != chs.end()) {
                char val = *it;
                string temp = prefix;
                temp.push_back(val);
                chs.erase(it);
                for (char x : chs)
                    temp.push_back(x);
                chs.insert(val);
                ans.push_back(temp);
            }
            auto nxt = chs.find(t[i]);
            if (nxt == chs.end())
                break;
            prefix.push_back(*nxt);
            chs.erase(nxt);
        }
        if (ans.size() == 0)
            return "";
        return *min_element(ans.begin(), ans.end());
    }
};