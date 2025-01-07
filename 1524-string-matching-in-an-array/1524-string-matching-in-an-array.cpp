class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            string word = words[i]; 
            int len = word.length();
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if ((int)word.length() >= (int)words[j].length())
                    continue;
                for (int k = 0; k < words[j].length(); k++) {
                    if (words[j].substr(k, len) == word)
                        ans.insert(word);
                }
            }
        }

        vector<string>str(ans.begin(),ans.end());

        return str;
    }
};