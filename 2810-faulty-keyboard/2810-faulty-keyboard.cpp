class Solution {
public:

    string finalString(string s) {
        string str="";
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]!='i')
                str+=s[i];
            else
                reverse(str.begin(),str.end());
        }
        return str;
    }
};