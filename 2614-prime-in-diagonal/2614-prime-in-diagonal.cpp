class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int len=nums.size();
        int maxPrime=0;

        for(int i=0;i<len;i++){
            int n=nums[i][i];
            if(IsPrime(n)) maxPrime=max(maxPrime,n);
            int m=nums[i][len-i-1];
            if(IsPrime(m)) maxPrime=max(maxPrime,m);
        }
        return maxPrime;
    }

    bool IsPrime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
};