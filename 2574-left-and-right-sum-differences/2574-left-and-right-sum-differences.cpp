class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);

        int sum1 = 0, sum2 = 0;

        // Calculate leftSum
        for (int i = 0; i < n; i++) {
            leftSum[i] = sum1;
            sum1 += nums[i];
        }

        // Calculate rightSum
        for (int i = n - 1; i >= 0; i--) {
            rightSum[i] = sum2;
            sum2 += nums[i];
        }

        vector<int> answer(n);

        // Calculate answer using leftSum and rightSum
        for (int i = 0; i < n; i++) {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }

        return answer;
    }
};
