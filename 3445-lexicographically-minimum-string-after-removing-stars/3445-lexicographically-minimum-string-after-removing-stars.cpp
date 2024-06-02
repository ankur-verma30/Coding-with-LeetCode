class Solution {
public:
    string clearStars(string s) {

        vector<char> ns(s.begin(), s.end());
         priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '*') {
                ns[i] = '\0';
                if (!pq.empty()) {
                    auto [ch, ind] = pq.top();
                    pq.pop();
                    ns[-ind] = '\0';
                }
            } else {
                pq.push({ch, -i});
            }
        }

        string result;
        for (char c : ns) {
            if (c != '\0') {
                result.push_back(c);
            }
        }

        return result;
    }
};