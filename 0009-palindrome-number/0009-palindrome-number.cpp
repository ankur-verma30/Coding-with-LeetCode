class Solution {
public:
    bool isPalindrome(int x) {
       long int rem,num=0,y=x;
    
    while(x>0)
          {
    rem=x%10;
    num=num*10+rem;
    x=x/10;
    }
   
        if(y==num)
            return true;
        else
            return false;      
  
    }
};