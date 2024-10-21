class Solution {
public:
    void Backtrack(int index,int n, string& s, set<string>& st, int& maxCount) {
        if (index == n) {
            maxCount = max(maxCount, (int)st.size());
            return;
        }

        for (int i = index; i < n; i++) {
            string str = s.substr(index, i - index + 1);
            if (st.count(str) == 0) {
                st.insert(str);
                Backtrack(i + 1,n, s, st, maxCount);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int maxCount = INT_MIN;
        int n=s.length();
        set<string> st;

        Backtrack(0,n, s, st, maxCount);
        return maxCount;
    }
};