class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        set<int> set1;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        
        
        for(auto x:mp)
            set1.insert(x.second);
        
        return(set1.size()>1)?false:true;
            
        
        
    }
};