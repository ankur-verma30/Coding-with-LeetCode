class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int TotalCharacters=0;
        unordered_map<char,int>mp;

        for(auto str:words){
            for(auto ch:str){
                TotalCharacters++;
                mp[ch]++;
            }
        }

        if(TotalCharacters%(int)words.size()!=0) return false; 

        for(auto x:mp){
            if(x.second%(int)words.size()!=0)
            return false;
        }

        return true;
    }
};