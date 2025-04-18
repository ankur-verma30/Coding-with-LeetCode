class Solution {
public:
    int mod = 1e9 + 7;
    long long fastExponentiation(int num, long long power) {
        int pro = 1, multiplier = num;

        while (power > 0) {
            if (power % 2)
                pro = (long long)pro * multiplier % mod;
            multiplier = (long long)multiplier * multiplier % mod;
            power /= 2;
        }
        return pro;
    }
    int countGoodNumbers(long long n) {
        if (n == 1)
            return 5;

        return fastExponentiation(5, (n + 1) / 2) *
               fastExponentiation(4, n / 2) % mod;
    }
};