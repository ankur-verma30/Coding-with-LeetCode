class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
           
            for (int j = 1; j < n; j++) {
                int first = __builtin_popcount(nums[j - 1]);
                int sec = __builtin_popcount(nums[j]);
                if (first == sec)
                    if (nums[j] < nums[j - 1])
                        swap(nums[j], nums[j - 1]);
            }
        }
         bool isSorted = true;
         for (int k = 1; k < n; k++) {
                if (nums[k - 1] > nums[k]) {
                    isSorted = false;
                    break;
                }
            }

            if (isSorted)
                return true;

        return false;
    }
};