class Solution {
public:

    int SumCount(int n){
        int rem=0;
        int res=0;
        while(n!=0){
            rem=n%10;
            res+=rem;
            n=n/10;
        }
        return res;
    }

    int countEven(int num) {
        int count=0;
        int i=2;
       while(i<=num){
            int data=SumCount(i);
            if(data%2==0 && data<=num)
            {
            count++;
            i++;
            }
            else
            i++;
        }
        return count;
    }

};