class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>sumPrefix;
        int ans=0,sum=0,n=nums.size();
        sumPrefix[0]=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) ans++;
            if(sumPrefix.find(sum-k)!=sumPrefix.end()){
                ans+=sumPrefix[sum-k];
            }
            sumPrefix[sum]++;
        }
        return ans;
    }
};