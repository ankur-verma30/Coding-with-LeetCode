class Solution {
public:
    int numSub(string s) {
        int n=s.length();
        long long count=0,mod=1e9+7;

        int ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++;
            else{
                long long val=(1L*ones*(ones+1))/2;
                count=(count+val)%mod;
                ones=0;
            }
        }
        int val=(ones*(ones+1))/2;
        count=(count+val)%mod;
        return count%mod;
    }
};