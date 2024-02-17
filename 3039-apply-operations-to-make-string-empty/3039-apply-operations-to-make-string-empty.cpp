class Solution {
public:
    string lastNonEmptyString(string s) {
        
        unordered_map<char,int>mp;
        int maxi=0;
        string res;
    
        
 for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
        }
        
        for(int i=s.length()-1;i>=0;i--){
            if(mp[s[i]]==maxi) {
                res+=s[i];
                mp[s[i]]=0;
            }
        }
        reverse(res.begin(),res.end());
        return res;
        
     
    }
};