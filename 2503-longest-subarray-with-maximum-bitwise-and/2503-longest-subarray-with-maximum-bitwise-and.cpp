class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = 0;
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[maxIndex] < nums[i])
                maxIndex = i;
        }

        int temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[maxIndex]) {
                temp++;
                size = max(temp, size);
            } else
                temp = 0;
        }

        return size;
    }
};