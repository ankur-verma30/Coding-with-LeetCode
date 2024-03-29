class Solution {
public:
    int numberOfSubstrings(string s) {
    int hash[3]={-1,-1,-1};
        int count=0;
        
        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']=i;
           int value=min(hash[0],hash[1]);
           count+=1+min(value,hash[2]);
        }
        
        return count;
    }
};