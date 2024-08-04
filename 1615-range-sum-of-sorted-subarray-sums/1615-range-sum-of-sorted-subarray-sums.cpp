class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sum;

    for (int i = 0; i < n; i++) {
        long long currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            sum.push_back(currentSum);
        }
    }


        for(int i=0;i<sum.size();i++) cout<<sum[i]<<" ";

        sort(sum.begin(),sum.end());

        int res=0;
        if(right>sum.size()) right=sum.size(); 
        for(int i=left-1;i<right;i++)  res = (res + sum[i]) % mod;

        return res;
    }
};