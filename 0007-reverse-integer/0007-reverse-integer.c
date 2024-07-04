int reverse(int y){

    long new_num=0;
        int rem=0;
        while(y!=0){  
            rem=y%10;
            new_num=new_num*10+rem;
             if(new_num>INT_MAX || new_num<INT_MIN) return 0;
            y/=10;
        }

        return new_num; 
}