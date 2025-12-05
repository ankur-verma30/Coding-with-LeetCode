class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        int count = 0, n = nums.size(), left = 0, maxPro = 1,minElement=INT_MAX;

        for (int right = 0; right < n; right++) {
            minElement=min(nums[right],minElement);
            maxPro *= nums[right];
            while (left < n && maxPro >= k) {
                maxPro /= nums[left++];
            }
            count += (right - left + 1);
        }

        if(minElement>=k) return 0;

        return count;
    }
};