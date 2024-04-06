class Solution {
public:
    string minRemoveToMakeValid(string s) {
      int open =0;
      string t="";
      for(int i=0;i<s.size();i++){
        if(s[i]=='(') open++;
        else if(s[i]==')'){
            if(open ==0) continue;
            open--;
        }
        t+=s[i];
      }

        string ans;
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='(' && open>0){
                open--;
                continue;
            }
            ans+=t[i];
        }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};