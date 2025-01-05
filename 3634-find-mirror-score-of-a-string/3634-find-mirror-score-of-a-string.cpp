class Solution {
public:
    long long calculateScore(string s) {
        int n = s.length();
        unordered_map<char, stack<int>> index;
         long long score = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            int dis = c - 'a';
            char mirror = 'z' - dis;

            if (index.count(mirror) && !index[mirror].empty()) {
                score += (i - index[mirror].top());
                index[mirror].pop();
            } else {
                index[c].push(i);
            }
        }

        return score;
    }
};