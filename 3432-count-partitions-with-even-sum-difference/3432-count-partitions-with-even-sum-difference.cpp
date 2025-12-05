class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0, count = 0, n = nums.size();

        for (const int num : nums)
            totalSum += num;

        int leftsum = 0;
        for (int i = 0; i < n-1; i++) {
            leftsum += nums[i];
            int rightsum = totalSum - leftsum;
            if ((leftsum - rightsum) % 2 == 0)
                count++;
        }

        return count;
    }
};