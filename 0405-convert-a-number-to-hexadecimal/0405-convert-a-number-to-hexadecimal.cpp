class Solution {
public:
    string toHex(int num) {
        if(num==0)   return "0";

        unordered_map<int,char> mp;
        char digit='0';
        char character='a';

        for(int i=0;i<=15;i++){
            if(i<10) 
            mp[i]=digit++;
            else 
            mp[i]=character++;
        }
           string res="";
        if(num>0){
            while(num){
                res=mp[num%16]+res;
                num/=16;
            }
        }
        else{
            u_int n=num;
             while(n){
                res=mp[n%16]+res;
                n/=16;
            }
        }
        return res;
    }
};