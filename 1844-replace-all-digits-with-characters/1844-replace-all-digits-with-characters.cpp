class Solution {
public:
    string replaceDigits(string& s) {
        int value=0;

        for(int i=0;i<s.length();i++){
            if(s[i]>=97 && s[i]<=122){
                value=s[i]-'a';
            }
            if(s[i]>=48 && s[i]<=57){
                int digit=s[i]-'0';
                s[i]='a'+digit+value;
            }
        }
        return s;
        
    }
};