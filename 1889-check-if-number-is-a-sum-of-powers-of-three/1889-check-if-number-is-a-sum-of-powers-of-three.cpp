class Solution {
public:
    void powerOfThree(int n,vector<int>&power){
       int i=1;
       while(i<=n){
        power.push_back(i);
        i=i*3;
       }
    }
    bool checkPowersOfThree(int n) {
       vector<int>power;
        powerOfThree(n,power);
        int i=power.size(),len=i-1;

        while(len>=0 && n>0){
            if(power[len]==n) return true;
            else if(power[len]<n)  n-=power[len];
                len--;
        }

       return n==0;
    }
};