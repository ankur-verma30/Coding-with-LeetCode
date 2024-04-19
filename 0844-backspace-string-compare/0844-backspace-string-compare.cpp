class Solution {
public:
    bool backspaceCompare(string s, string t) {
       string ans1="";
       string ans2="";

       for(int i=0;i<s.length();i++){
        if(s[i]=='#'){
            if(ans1=="") continue;
            else ans1.pop_back();
        }
        else ans1+=s[i];
       }

        for(int i=0;i<t.length();i++){
       if(t[i]=='#'){
            if(ans2=="") continue;
            else ans2.pop_back();
        }
        else ans2+=t[i];
       }

       return (ans1==ans2)?true:false;


    }
};