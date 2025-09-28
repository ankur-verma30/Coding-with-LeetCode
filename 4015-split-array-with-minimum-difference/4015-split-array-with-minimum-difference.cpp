class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> leftPrefix(n, 0);
        leftPrefix[0] = nums[0];
        vector<bool> left(n, false);
        left[0] = true;

        for (int i = 1; i < n; i++) {
            leftPrefix[i] = leftPrefix[i - 1] + nums[i];
            if (nums[i] > nums[i - 1] && left[i - 1])
                left[i] = true;
        }

        vector<long long> rightSuffix(n, 0);
        rightSuffix[n - 1] = nums[n - 1];
        vector<bool> right(n, false);
        right[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            rightSuffix[i] = nums[i] + rightSuffix[i + 1];
            if (nums[i] > nums[i + 1] && right[i + 1])
                right[i] = true;
        }

        long long mini = LLONG_MAX;
        for (int i = 0; i < n - 1; i++) {
            if (left[i] && right[i + 1]) {
                long long diff = llabs(leftPrefix[i] - rightSuffix[i + 1]);
                mini = min(mini, diff);
            }
        }
        return mini == LLONG_MAX ? -1 : mini;
    }
};
