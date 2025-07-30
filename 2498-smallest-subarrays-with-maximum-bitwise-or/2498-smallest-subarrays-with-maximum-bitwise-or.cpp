class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> freqBits(32, -1);
        vector<int> result(n);

        for (int i = n - 1; i >= 0; i--) {
            int farthestPosition = i;

            for (int bits = 0; bits <= 31; bits++) {
                if (nums[i] & (1 << bits))
                    freqBits[bits] = i;
                if (freqBits[bits] != -1)
                    farthestPosition = max(farthestPosition, freqBits[bits]);
            }
            result[i] = farthestPosition - i + 1;
        }
        return result;
    }
};