class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
      int result = 0;
    int n = nums.size();

    for (int i = 31; i >= 0; --i) {
        int count = 0;
        for (int num : nums) {
            if ((num >> i) & 1) {
                count++;
            }
        }

        if (count >= k) {
            result |= (1 << i);
        }
    }

    return result;   
    }
};