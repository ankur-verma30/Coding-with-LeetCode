class Solution {
public:
    long long coloredCells(int n) {
      if(n==1) return 1;

     long long val=1;
     for(int i=1;i<n;i++){
        long long diff=i*4;
        val+=diff;
     }

     return val;
    }
};