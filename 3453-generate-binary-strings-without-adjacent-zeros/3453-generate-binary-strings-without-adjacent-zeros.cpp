class Solution {
public:
    void create(int n, string curr, vector<string>& ans) {

        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        if (curr.empty() || curr.back() == '1') {
            create(n, curr + "0", ans);
        }
        create(n, curr + "1", ans);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        create(n, "", ans);
        return ans;
    }
};