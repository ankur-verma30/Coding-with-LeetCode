class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n=nums.size();

        vector<int>prefixGcd(n,0);
        int maxi=nums[0];
        prefixGcd[0]=nums[0];

        for(int i=1;i<nums.size();i++){
            maxi=max(nums[i],maxi);
            prefixGcd[i]=__gcd(nums[i],maxi);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        long long sum=0;

        for(int i=0;i<n/2;i++){
            int gcd=__gcd(prefixGcd[i],prefixGcd[n-i-1]);
            sum+=gcd;
        }

        return sum;

    }
};