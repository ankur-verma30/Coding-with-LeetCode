class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        string res="";
        char ch;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(stk.empty()){
                stk.push(s[i]);
            }
            else{
                 ch=stk.top();
                if (s[i]+32==ch || s[i]-32==ch )
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        while(!stk.empty()){
             ch=stk.top();
        res+=ch;
        stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};