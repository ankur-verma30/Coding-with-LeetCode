class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
         int n=nums.size();
        vector<int>preXor(n,0);
        int xorVal=0;

        for(int i=0;i<n;i++){
            xorVal^=nums[i];
            preXor[i]=xorVal;
        }
        

        reverse(preXor.begin(),preXor.end());

        int maxK=(1<<maximumBit)-1;
        for(int i=0;i<n;i++){
            int k=maxK^preXor[i];
           preXor[i]=k;
        }

        return preXor;
    }
};