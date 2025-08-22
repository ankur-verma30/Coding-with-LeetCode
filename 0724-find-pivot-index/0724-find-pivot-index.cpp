class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, totalSum = 0;

        for (const auto& num : nums)
            totalSum += num;

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum;
            leftSum += nums[i];
            if (leftSum == rightSum)
                return i;
        }

        return -1;
    }
};