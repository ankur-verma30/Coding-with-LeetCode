class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
         int n = nums.size();
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    
    for (int shift = 0; shift < n; shift++) {
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != sorted_nums[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return shift;
        }
        
        // Perform a right shift
        int last = nums[n - 1];
        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }
        nums[0] = last;
    }
    
    return -1;
    }
};