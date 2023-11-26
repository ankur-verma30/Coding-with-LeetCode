class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        int BitsToReverse=32;
        
        while(BitsToReverse--){
            result=(result<<1)|(n&1);
            n>>=1;
        }
        return result;
    }
};