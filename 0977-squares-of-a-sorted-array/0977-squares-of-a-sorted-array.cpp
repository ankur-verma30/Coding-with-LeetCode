class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len=nums.size();
        int l=0,r=len-1;

        vector<int>ans(len);

        for(int i=len-1;i>=0;i--){
            int xl=nums[l]*nums[l];
            int xr=nums[r]*nums[r];

            if(xl>xr){
                ans[i]=xl;
                l++;
            }
            else{
                ans[i]=xr;
                r--;
            }
        }
        return ans;
    }
};