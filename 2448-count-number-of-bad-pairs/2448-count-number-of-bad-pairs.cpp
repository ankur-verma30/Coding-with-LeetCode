class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long n=nums.size();
       long long  totalPairs=(n*(n-1))/2;

       unordered_map<long long,long long>mp;

       for(int i=0;i<n;i++){
        long long diff=i-nums[i];
        mp[diff]++;
       }
 
       for(const auto &[diff,count]:mp){
        long long pairs=(count*(count-1))/2;
        totalPairs-=pairs;
       }

       return totalPairs;
    }
};