class Solution {

public:
    int smallestNumber(int n) {
        string bits;

        while(n>0){
            int val=(n&1);
            bits+=(val+'0');
            n=n>>1;
        }

        bool allOne=true;
        int len=bits.length();

        for(int i=0;i<len;i++){
            if(bits[i]=='0') bits[i]=1;      
        }

        return (1<<len)-1;

    }
};