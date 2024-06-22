class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (count % 2 == 1)
                nums[i] ^= 1;

            if (nums[i] == 0)
                count++;
        }

        return count;
    }
};