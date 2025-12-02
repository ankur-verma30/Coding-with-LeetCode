class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size(),left=0;
        vector<int>power(n,0);
        vector<int>ans(n-k+1,0);
        power[0]=1;

        for(int i=1;i<n;i++){
            if(nums[i-1]+1==nums[i]) power[i]+=power[i-1]+1;
            else power[i]=1;
        }

        for(int right=0;right<n;right++){
            if(right-left+1>=k ){
                if(power[right]>=k) ans[left++]=nums[right];
            else ans[left++]=-1;
        }
        }            
        return ans;
    }
};