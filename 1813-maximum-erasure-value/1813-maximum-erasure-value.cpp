class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0,maxSum=0,n=nums.size(),sum=0;
        unordered_map<int,int>mp;

        for(int right=0;right<n;right++){
            sum+=nums[right];
            mp[nums[right]]++;

            if(mp[nums[right]]>1){
                while(mp[nums[right]]>1 && left<n){
                    sum-=nums[left];
                    mp[nums[left]]--;
                    if(mp[nums[left]]==0) mp.erase(nums[left]);
                    left++;
                }
            }
            maxSum=max(maxSum,sum);
        }

        return maxSum;
    }
};