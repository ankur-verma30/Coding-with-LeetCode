class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        set<char> st{'a', 'e', 'i', 'o', 'u'};
        int n = words.size(), previousSum = 0;

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            string word = words[i];
            int len = word.length();
            if (st.count(word[0]) && st.count(word[len - 1]))
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i];
        }

        vector<int> ans;

        for (const auto query : queries) {
            int first = query[0], second = query[1];
            ans.push_back(prefix[second + 1] - prefix[first]);
        }

        return ans;
    }
};