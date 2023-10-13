class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        string res="";
        int len=s.length();
        char ch;
    
        for(int i=0;i<len;i++){
            if(!stk.empty())
            {
               ch=stk.top();
             if(ch==s[i])
                 stk.pop();
            
            else
                stk.push(s[i]);
            }
        else
            stk.push(s[i]);
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