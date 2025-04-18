class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mpp;

        for (const auto& ch : s)
            mpp[ch]++;

        string temp;
        char c;
        bool flag = false;

        for (const auto& [ch, freq] : mpp) {
            if (freq % 2) {
                c = ch;
                flag = true;
            }
            int half = freq / 2;
            while (half--)
                temp += ch;
        }
        string other_half=temp;
        if(!temp.empty())
        reverse(temp.begin(), temp.end());
        string ans;
        if (flag) {
            ans +=other_half+c+temp;
            return ans;
            }
        return other_half+temp;
    }
};