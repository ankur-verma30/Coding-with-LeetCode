class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0,NextSum=0,value=0;
        for(int i=0;i<s.length();i++){
            value=(s[i]-'a')+1;
            sum+=SumOfDigits(value);
        }

        if(k==1) return sum;
        else if(sum<10) return sum;
        else{
            while(k-1!=0){
                NextSum=SumOfDigits(sum);
                sum=NextSum;
                k--;
            }
            return sum;
        }    
    }
    
    private:

    int SumOfDigits(int n){
        int sum=0;
        if(n<10)
        return n;
        else{
            while(n>0){
                int rem=n%10;
                sum+=rem;
                n=n/10;
            }
        }
        return sum;
    }
};