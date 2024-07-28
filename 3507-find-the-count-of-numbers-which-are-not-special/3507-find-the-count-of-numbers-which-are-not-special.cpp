class Solution {
public:
    bool prime(long long n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int nonSpecialCount(int l, int r) {
        int range = r - l + 1;
        int count = 0;
        long long root = sqrt(l);

        if (root * root != l)
            root++;

        for (long long i = root; i * i <= r; i++) {
            if (prime(i))
                count++;
        }

        return range - count;
    }
};