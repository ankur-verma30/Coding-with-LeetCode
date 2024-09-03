class Solution {
public:
    int SumofDigits(int num){
        int newNum=0;
        while(num>0){
            int rem=num%10;
            newNum+=rem;
            num/=10;
        }
        return newNum;
    }
    
    int getLucky(string s, int k) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int val=(s[i]-'a')+1;
            sum+=SumofDigits(val);
        }
        int NewSum=0;
        if(k==1) return sum;
        else if(sum<10) return sum;
        else{
            while(k-1!=0){
                NewSum=SumofDigits(sum);
                sum=NewSum;
                k--;
            }
        }

        return sum;

    }
};