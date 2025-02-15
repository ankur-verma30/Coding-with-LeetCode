class Solution {
public:
 
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n=nums.size(),sum=0;

        for(int i=0;i<n;i++){
            bool f1=true,f2=true;
            if(i-k>=0 && nums[i]<=nums[i-k]) f1=false;
            else if(i+k<n && nums[i]<=nums[i+k]) f2=false;

            if(f1 && f2) sum+=nums[i];
           
        }

        return sum;
    }
};