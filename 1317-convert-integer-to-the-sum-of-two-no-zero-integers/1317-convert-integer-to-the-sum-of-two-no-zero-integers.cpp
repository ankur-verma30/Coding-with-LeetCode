class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int low=1,high=n-1;

        while(low<=high){
         if(CheckZeroes(low) || CheckZeroes(high)){
                low++;
                high--;
            }
            else if(!(CheckZeroes(low) && CheckZeroes(high))){
                if(low+high==n) return {low,high};
            }
        }
        return {-1};
        
    }

    private:
    bool CheckZeroes(int n){
        while(n>0){
            int rem=n%10;
            if(rem==0) return true;
            n=n/10;
        }
        return false;
    }
};