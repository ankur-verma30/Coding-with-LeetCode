class Solution {
public:
    bool check(vector<int>& nums) {
        int rotateIndex = -1, n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                rotateIndex = i;
        }

        if (rotateIndex == -1)
            return true;

        reverse(nums.begin(), nums.begin() + rotateIndex);
        reverse(nums.begin() + rotateIndex , nums.end());
        reverse(nums.begin(), nums.end());

        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                sorted = false;
                break;
            }
        }

        return sorted;
    }
};