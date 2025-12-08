class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0, n = nums.size();
        long long maxSum = 0, sum = 0;

        unordered_map<int, int> mpp;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            mpp[nums[right]]++;

            if (right - left + 1 > k) {
                sum -= nums[left];
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);
                left++;
            }

            while (mpp.count(nums[right])>1) {
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) mpp.erase(nums[left]);
                left++;
            }

            if (right - left + 1 == k && mpp.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};