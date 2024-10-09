class Solution {
public:
    string stringHash(string s, int k) {
    
        string res;
        int i = 0;
        for (; i < s.length();) {
            int count = k;
            int sum = 0;
            while (count--) {
                int val = s[i] - 'a';
                sum += val;
                i++;
            }
            sum = sum % 26;
            char ch = sum+'a';
            res += ch;
            
        }
        return res;
    }
};