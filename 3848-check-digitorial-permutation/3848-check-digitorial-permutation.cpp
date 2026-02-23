class Solution {
    unordered_map<int, int> mpp{{0, 1},     {1, 1},     {2, 2},   {3, 6},
                                {4, 24},    {5, 120},   {6, 720}, {7, 5040},
                                {8, 40320}, {9, 362880}};

public:
    bool isDigitorialPermutation(int n) {
        unordered_map<int, int> map;
        long long sum = 0;

        while (n > 0) {
            int rem = n % 10;
            sum += mpp[rem];
            map[rem]++;
            n /= 10;
        }

        while (sum > 0) {
            int rem = sum % 10;
            map[rem]--;
            if (map[rem] == 0)
                map.erase(rem);
            sum /= 10;
        }

        return map.empty();
    }
};