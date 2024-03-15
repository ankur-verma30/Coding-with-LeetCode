class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int zeroes=0;
        int product=1;

      for(int i=0;i<n;i++){
        if(nums[i]==0) {
            zeroes++;
            continue;
        }
        product*=nums[i];
      }

      if(zeroes==0){
        for(int i=0;i<n;i++) ans[i]=product/nums[i];
      }

      if(zeroes==1){
        for(int i=0;i<n;i++){
            ans[i] = nums[i] == 0 ? product : 0;
        }
      }

      if(zeroes>=2){
        for(int i=0;i<n;i++) ans[i]=0;
      }

        return ans;
    }
};