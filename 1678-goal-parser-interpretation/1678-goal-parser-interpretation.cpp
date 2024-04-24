class Solution {
public:
    string interpret(string s) {
        string res="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='G') res+='G';

            else if(s[i]=='(' && s[i+1]==')'){
                res+='o';
                i++; \
                continue;
            }
            else if(s[i]=='(' && s[i+1]=='a'){
                res+="al";
                i=i+3;
                continue;
            }
        }

        return res;
    }
};