class Solution {
public:
    string clearDigits(string s) {
        string str;
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch>='a' && ch<='z' ) str+=ch;
            
            else if(ch-'0'>=0 && ch-'0'<=9){
                if((int )str.length()!=0) str.pop_back();
                else continue;
            }
        }
        return str;
    }
};