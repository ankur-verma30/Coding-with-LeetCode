class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                count++;
          
        }

        if (count == 0)
            return false;

       return true;
    }
};