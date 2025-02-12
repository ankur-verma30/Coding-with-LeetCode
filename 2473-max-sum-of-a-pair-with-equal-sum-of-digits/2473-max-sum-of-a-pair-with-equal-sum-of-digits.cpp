class Solution {
public:
    int sumOfDigits(int num){
        int sum=0;

        while(num>0){
            sum+=(num%10);
            num/=10;
        }

        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans=-1;

        for(const auto num:nums){
           int sum=sumOfDigits(num);
           if(mpp.find(sum)!=mpp.end()){
            ans=max(num+mpp[sum],ans);
            if(num>mpp[sum]) mpp[sum]=num;
           }
           else mpp[sum]=num;
        }

        return ans;
    }
};