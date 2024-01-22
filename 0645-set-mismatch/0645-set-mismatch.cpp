class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        // xor of indexes and values in array
        for (int i = 0; i < n; i++)
            xor1 ^= (nums[i] ^ (i + 1));

        // Finding least significant SetBit
        int k = 0;
        while ((xor1 & (1 << k)) == 0)
            k++;

        // Find xor_num of SetBit at position k(from left)
        int xor_num = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] & (1 << k)) != 0)
                xor_num ^= nums[i];
            if (((i + 1) & (1 << k)) != 0)
                xor_num ^= (i + 1);
        }

        // Converting xor1 and xor_num as answer
        xor1 = xor1 ^ xor_num;

        // Checking which one is present in array (ie duplicate element)
        for (int i = 0; i < n; i++) {
            if (nums[i] == xor1)
                return {xor1, xor_num};
        }
        return {xor_num, xor1};
    }
};