class Solution {
public:
    string stringHash(string s, int k) {
        unordered_map<char, int> mpp;
        char ch = 'a';

        for (int i = 0; i < 26; i++)
            mpp[i] = ch++;

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
            char ch = mpp[sum];
            res += ch;
            
        }
        return res;
    }
};