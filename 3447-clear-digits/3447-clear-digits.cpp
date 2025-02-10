class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]<='z' && s[i]>='a') st.push(s[i]);
            else st.pop();
        }

        string str;

        while(!st.empty()){
            char ch=st.top();
            str+=ch;
            st.pop();
        }

        reverse(str.begin(),str.end());
        return str;
    }
};