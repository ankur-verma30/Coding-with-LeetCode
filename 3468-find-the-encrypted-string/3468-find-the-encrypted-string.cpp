class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        string y = s;
        int n = s.length();
        for (int i = 0; i < s.length(); i++) {
            int val = (i + k) % n;
            y[i] = s[val];
        }
        return y;
    }
};