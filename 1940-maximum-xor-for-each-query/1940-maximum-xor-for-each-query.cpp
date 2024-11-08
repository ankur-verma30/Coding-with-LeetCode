class Solution {
public:
    int MaximumK(int maximumBit,int n){
         int mask = (1 << maximumBit) - 1; 
        int inverted = ~n & mask; 
        return inverted; 
    }
    
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int>preXor(n,0);
        int xorVal=0;

        for(int i=0;i<n;i++){
            xorVal^=nums[i];
            preXor[i]=xorVal;
        }

        vector<int>ans;
        int maxK=(1<<maximumBit)-1;
        for(int i=n-1;i>=0;i--){
            int k=MaximumK(maximumBit,preXor[i]);
            ans.push_back(k);
        }

        return ans;
    }
};