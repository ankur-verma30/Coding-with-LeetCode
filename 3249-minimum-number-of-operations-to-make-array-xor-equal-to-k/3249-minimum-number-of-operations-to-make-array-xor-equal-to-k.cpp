class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorVal = 0;
        for (auto x : nums)
            xorVal ^= x;

        if (xorVal == k)
            return 0;

        int count = 0;
        for (int i = 0; i < 31; i++) {
            if (((xorVal >> i) & 1) != ((k >> i) & 1))
                count++;
        }

        return count;
    }
};