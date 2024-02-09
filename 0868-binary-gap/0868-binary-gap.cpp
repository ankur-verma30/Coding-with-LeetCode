class Solution {
public:
    int binaryGap(int n) {
      int maxGap=0;
      int previousCount=0,count=0;

      while(n!=0){
          count++;
          if(n & 1){
              if(previousCount==0) previousCount=count;
              else{
                  int diff=count-previousCount;
                  maxGap=max(maxGap,diff);
                  previousCount=count;
              }
          }
          n=n>>1;
      }  
      return maxGap;
    }
};