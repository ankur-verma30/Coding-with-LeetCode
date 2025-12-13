class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int low=0,high=x/2,ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(1LL*mid*mid==x) return mid;
            else if(1LL*mid*mid<x) low=mid+1;
            else high=mid-1;
        }

        return high;
        
    }
};