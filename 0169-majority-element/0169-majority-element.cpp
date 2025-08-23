class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxi=0,ans=0;
        unordered_map<int,int>mpp;

        for(const auto it:nums){
            mpp[it]++;
            if(mpp[it]>maxi){
                maxi=mpp[it];
                ans=it;
            }
        }

        return ans;
    }
};