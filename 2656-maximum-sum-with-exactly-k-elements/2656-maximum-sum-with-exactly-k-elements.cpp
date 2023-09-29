class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(mx<nums[i])
            mx=nums[i];
        }


        
        while(k!=0){
        sum+=mx;
          mx++;
           k--;

        }
        return sum;
    }
};