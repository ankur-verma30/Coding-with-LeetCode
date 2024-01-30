class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int low = 0, high = nums.size() - 1;
        int duplicate = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < mid + 1) {
                duplicate = nums[mid];
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return duplicate;
    }
};