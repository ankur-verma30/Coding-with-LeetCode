class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string res;
        int n = target.length();

        for (int i = 0; i < n; i++) {
            char ch = target[i];
            char temp = 'a';
            while (temp <= ch) {
                if (res.empty()){
                    string curr;
                    curr+=temp;
                    ans.push_back(curr);
                }
                else {
                    string curr = res;
                    curr += temp;
                    ans.push_back(curr);
                }
                temp++;
            }
            temp--;
            res += temp;
        }

        return ans;
    }
};