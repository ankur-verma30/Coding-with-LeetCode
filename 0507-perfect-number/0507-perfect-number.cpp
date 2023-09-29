class Solution {
public:
    bool checkPerfectNumber(int num) {
         int sum=0;
        for(int i=num/2;i>=1;i--){
            if(num%i==0)
                sum+=i;}
      return (sum==num)?true:false;    }};