class Solution {
public:
    string toLowerCase(string s) {
        string str="";

        for(int i=0;i<s.size();i++ ){
            if(s[i]>=65 && s[i]<=90)
            str+=char(int(s[i])+32);
            else
            str+=s[i];
        }
        return str;
    }

};