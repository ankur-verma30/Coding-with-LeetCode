class Solution {
public:
    string operationalString(string &str){
        string st;
        int len=str.length();
        for(int i=1;i<len;i++){
            int sum=((str[i-1]-'0')+(str[i]-'0'));
            int rem=sum%10;
            st+=to_string(rem);
        }

        return st;
    }
    bool hasSameDigits(string s) {
        int n=s.length();

        string ans=operationalString(s);
        while(ans.size()>2){
            ans=operationalString(ans);
        }

        if(ans.size()==2){
            if(ans[0]==ans[1]) return true;
        }

        return false;
        
    }
};