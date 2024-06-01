class Solution {
public:
    int scoreOfString(string s) {

        int count = 0;
        for (int i = 1; i < s.length(); i++) {

            int a = s[i] - 'a';
            int b = s[i - 1] - 'a';
            count += abs(a - b);
        }
        return count;
    }
};