class Solution {
public:
    int reverse(int x) {
        long y=x;//store into new variable
        bool value=false;
        if(y<0){//if input value is negative make value false and number positive
          value=false;
          y=-1*y;
        }
        else
        value=true;



    long new_num=0;
        int rem=0;
        while(y!=0){  //perfom reverse operation
            rem=y%10;
            new_num=new_num*10+rem;
            y/=10;
        }
        if(new_num>INT_MAX || new_num<INT_MIN)//if value is out of bound return 0
        return 0;
        else
        return (value ==false)?new_num*-1:new_num; //else reutrn number
        }
};