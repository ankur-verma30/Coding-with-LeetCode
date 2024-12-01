class Solution {

public:
    int smallestNumber(int n) {
        string bits;

        while(n>0){
            int val=(n&1);
            bits+=(val+'0');
            n=n>>1;
        }
        int len=bits.length();

        return (1<<len)-1;

    }
};