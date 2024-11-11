class Solution {
public:
    void generatePrime(vector<int>& sieve) {
        int N = sieve.size() - 1;
        sieve[0] = sieve[1] = 0;

        for (int i = 2; i * i <= N; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= N; j += i)
                    sieve[j] = 0;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        vector<int> sieve(1000 + 1, 1);
        generatePrime(sieve);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                continue;

            for (int canBePrime = 2; canBePrime < nums[i]; canBePrime++) {
                if (sieve[canBePrime] && nums[i] - canBePrime < nums[i + 1]) {
                    nums[i] -= canBePrime;
                    break;
                }
            }
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
};