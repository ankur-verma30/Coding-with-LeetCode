class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return;

        int low = 0, high = len - 1;
        int temp;

        while (low != high) {
            while ((nums[low] == 0) && (low < high))
                low++;
            while ((nums[high] != 0) && (low < high))
                high--;
            if (low != high) {
                temp = nums[low];
                nums[low] = nums[high];
                nums[high] = temp;
            }
        }
        high = len - 1;
        while (low != high) {
            while ((nums[low] == 1) && (low < high))
                low++;
            while ((nums[high] != 1) && (low < high))
                high--;
            if (low != high) {
                temp = nums[low];
                nums[low] = nums[high];
                nums[high] = temp;
            }
        }
    }
};