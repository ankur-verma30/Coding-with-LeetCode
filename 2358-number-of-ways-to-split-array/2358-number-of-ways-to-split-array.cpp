class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefixSum(n,0);
        prefixSum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }

        long long sum=prefixSum[n-1];
        int count=0;

        for(int i=0;i<n-1;i++){
            long long remaining=sum-prefixSum[i];
            if(remaining<=prefixSum[i]) count++;
        }

        return count;
    }
};