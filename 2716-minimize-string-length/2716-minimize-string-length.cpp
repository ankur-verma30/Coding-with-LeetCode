class Solution {
public:
    int minimizedStringLength(string s) {
        string res="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        
        for(auto x:mp)
                res+=x.first;
        return res.length();
}
};