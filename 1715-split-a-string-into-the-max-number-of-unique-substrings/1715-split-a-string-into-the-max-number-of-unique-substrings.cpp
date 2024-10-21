class Solution {
public:
    void Backtrack(int index, string& s, set<string>& st, int& maxCount) {
        int n = s.length();
        if (index == n) {
            maxCount = max(maxCount, (int)st.size());
            return;
        }

        for (int i = index; i < n; i++) {
            string str = s.substr(index, i - index + 1);
            if (st.count(str) == 0) {
                st.insert(str);
                Backtrack(i + 1, s, st, maxCount);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int maxCount = INT_MIN;
        set<string> st;

        Backtrack(0, s, st, maxCount);
        return maxCount;
    }
};