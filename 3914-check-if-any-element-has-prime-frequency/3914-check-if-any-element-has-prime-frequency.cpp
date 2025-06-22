class Solution {
public:
    bool isPrime(int n) {
        if(n<=1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (const auto it : nums)
            mpp[it]++;

        for (const auto& [num, freq] : mpp) {
            if (isPrime(freq))
                return true;
        }

        return false;
    }
};