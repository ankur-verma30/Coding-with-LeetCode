class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>bitsCount(32,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int bit=0;bit<=31;bit++){
                if(nums[i] & (1 << bit)) bitsCount[bit]++;
            }
        }

        for(int num=1;num<n;num++){
            for(int bit=0;bit<=31;bit++){
                if(num & (1 << bit)) bitsCount[bit]--;
            }
        }
        int ans=0;
        for(int i=0;i<=31;i++){
            if(bitsCount[i]>0) ans+=(1<<i);
        }

        return ans;
    }
};