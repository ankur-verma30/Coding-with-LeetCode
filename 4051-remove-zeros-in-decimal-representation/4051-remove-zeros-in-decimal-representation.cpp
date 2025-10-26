class Solution {
public:
    long long removeZeros(long long n) {
        string str="";

        while(n>0){
            int rem=n%10;
            if(rem!=0) str+=to_string(rem); 
            n=n/10;
        }

        reverse(str.begin(),str.end());

        long long ans=0;
        for(int i=0;i<str.length();i++){
            int digit=str[i]-'0';
            ans=(ans*10)+digit;
        }

        return ans;
    }
};