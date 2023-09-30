class Solution {
public:
    int sumBase(int n, int k) {


        int rem=0,res=0;
        int total=0;

        while(n!=0){  //value at base k in reversed manner
            rem=n%k;
            res=res*10+rem;
            n/=k;
        }

        while(res!=0){
        rem=res%10;
        total+=rem;
        res/=10;
        }
       
        return total;
    }
};