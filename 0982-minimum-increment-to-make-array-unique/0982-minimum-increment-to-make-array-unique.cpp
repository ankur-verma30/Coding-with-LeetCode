class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int>freq(*max_element(nums.begin(),nums.end())+1+(int)nums.size(),0);

        for(auto& x:nums) freq[x]++;
        int ans=0;

        for(int i=0;i<freq.size();i++){
            if(freq[i]<=1) continue;
            int extra=freq[i]-1;
            freq[i+1]+=extra;
            ans+=extra;
        }

        return ans;
    }
};