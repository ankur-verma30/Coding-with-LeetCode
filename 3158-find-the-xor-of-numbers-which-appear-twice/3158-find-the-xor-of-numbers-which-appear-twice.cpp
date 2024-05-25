class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans=0;
            
            for(auto &x:nums) mpp[x]++;
        
        for(auto &x:mpp){
            if(x.second==2){
                ans^=x.first;
            }
        }
        
        return ans;
    }
};