class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            string currString = s.substr(0, i + 1);
            int length = i + 1;
            if (n % length == 0) {
                bool isMatched=true;
                for (int j = 0; j< n; j+=length) {
                    string temp=s.substr(j,length);
                    if(temp!=currString) {
                        isMatched=false;
                        break;
                    }
                }
                     if (isMatched) return true;
            }
        }
        return false;
    }
};