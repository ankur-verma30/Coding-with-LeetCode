class Solution {
public:
    void solve(stack<char>& st, string& part) {
        int m = part.length();
        string ans;
        bool flag = false;

        int index = m - 1;
        while (index >= 0) {
            if (st.top() == part[index]) {
                ans += st.top();
                st.pop();
            } else {
                flag = true;
                break;
            }
            index--;
        }

        if (flag && index >= 0) {
            reverse(ans.begin(), ans.end());
            for (const auto ch : ans)
                st.push(ch);
        }
    }
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {
                st.push(s[i]);
             if (st.size() >= m && st.top() == part[m - 1]) {
                solve(st, part);
            }
        }

        string res;
        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            res += ch;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};