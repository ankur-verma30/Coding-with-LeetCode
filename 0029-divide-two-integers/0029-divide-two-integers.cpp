class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(divisor==1) return dividend;
        if(divisor==-1) return -1*dividend;    

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        for (int i = 31; i >= 0; i--) {
            if ((b << i) <= a) {
            a -= (b << i);
            quotient |= (1 << i);
        }
    }
        return (sign*quotient > INT_MAX)? INT_MAX:sign*quotient;
        return (sign*quotient < INT_MIN)? INT_MIN:sign*quotient;
    }
};