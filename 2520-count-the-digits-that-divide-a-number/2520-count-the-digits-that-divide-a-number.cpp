class Solution {
public:
    int countDigits(int num) {
        int y=0,rem=0,count=0;
       if(num<10)
       return 1;
       if(num>=10)
       { y=num;
           while(num>0)
           {
               rem=num%10;
               num/=10;
               if(y%rem==0)
               count++;
           }
       }
       return count;
       return 0;

    }
};