class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
        return 1;
       int result = 0, value = 0, k = 0;
        while (n > 0) {
            if ((n & 1) == 0) {
                value = 1 << k;
                result += value;
            }
            k++;
            n = n >> 1;
        }
        return result;
    }
    
};