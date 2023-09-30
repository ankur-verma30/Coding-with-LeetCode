int addDigits(int num){
    int rem=0,d=0;
if(num<=9)
    return num;     
        while(num>0)
        {        
            d=num%10;
            num=num/10;
            rem+=d;     
        }
     if(rem<=9)
            return rem;
                if(rem>9) 
                  return  addDigits(rem);
return 0;
}