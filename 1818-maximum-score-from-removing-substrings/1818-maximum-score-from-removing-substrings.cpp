class Solution {
public:
    int points(string& s, string temp, int x) {
        stack<char> st;
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty())
                st.push(s[i]);
            else {
                if (s[i] == temp[1] && st.top() == temp[0]) {
                    total += x;
                    st.pop();
                } else
                    st.push(s[i]);
            }
        }

        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return total;
    }

    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if (x < y)
            swap(s1, s2), swap(x, y);
        return points(s, s1, x) + points(s, s2, y);
    }
};