class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for (int i = 0; i < n; i++) {
            string str = s;
            reverse(str.begin() + i, str.end());
            reverse(str.begin(), str.begin() + i);
            reverse(str.begin(), str.end());
            if (str == goal)
                return true;
        }

        return false;
    }
};