class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isOnePresent=false;
        int n=nums.size();

        for(const auto num:nums){
            if(num==1){
                isOnePresent=true;
                break;
            }
        }

        if(!isOnePresent) return 1;
        for(int i=0;i<n;i++){
            if(nums[i]<1 || nums[i]>n) nums[i]=1;
        }

        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1]*=-1;
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }

        return n+1;
    }
};