class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()==1) return false;
        unordered_map<int, int> mpp;

        for (auto& x : deck)
            mpp[x]++;

        int val=mpp[deck[0]];
        for (auto& x : mpp) {
           if(val==1) return false;
           val=__gcd(val,x.second);
        }
        

        return true;
    }
};