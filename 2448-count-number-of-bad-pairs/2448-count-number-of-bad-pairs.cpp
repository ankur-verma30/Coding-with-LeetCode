class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       
        int n=nums.size();
        long long ans=0;

       unordered_map<long long,int>goodPairs;

       for(int i=0;i<n;i++){
        long long diff=i-nums[i];
        int goodPairCount=goodPairs[diff];
        ans+=(i-goodPairCount);
        goodPairs[diff]++;
        
       }

      
       return ans;
    }
};