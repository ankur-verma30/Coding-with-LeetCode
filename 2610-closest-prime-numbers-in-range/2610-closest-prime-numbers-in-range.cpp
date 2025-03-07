class Solution {
public:
    void sieveOfEratosthenes(vector<bool>& sieve, int N) {
        sieve[0] = sieve[1] = false;
        for (long long i = 2; i <= N; i++) {
            if (sieve[i]) {
                for (long long j = i * i; j <= N; j += i)
                    sieve[j] = false;
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right + 1, 1);
        sieveOfEratosthenes(sieve, right);

        int first = -1, second = -1,lastPrime=-1;

       for (int i = left; i <= right; i++) {
            if (sieve[i]) {
                if (lastPrime != -1) {
                    if (first == -1 || (i - lastPrime < second - first)) {
                        first = lastPrime;
                        second = i;
                    }
                }
                lastPrime = i;
            }
        }


       
        return {first, second};
    }
};