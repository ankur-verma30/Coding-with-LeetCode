class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result=0;
        for(int i=left;i<=right;i++){
            int count=CountBits(i);
            if(CheckPrime(count))
            result++;
        }
        return result;
    }
    
    private:
    bool CheckPrime(int n){
        if(n<=1)
        return false;

        for(int i=2;i<=n/2;i++){
            if(n%i==0)
            return false;
        }
        return true;
    }

    int CountBits(int n){
        int ans=0;
        while(n){
          n=n & (n-1);
          ans++;
        }
        return ans;
    }
    
};