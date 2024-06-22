class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
    for (int num : nums) {
        int rem = num % 3;
        if (rem != 0) {
            count += min(rem, 3 - rem);
        }
    }
    return count;
    }
};