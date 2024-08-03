class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count0 = count(nums.begin(), nums.end(), 0);

        int Windowcount1 = count(nums.begin(), nums.begin() + count0, 1);
        int minSwap = Windowcount1;

        int left = 0, right = count0;
        while (left < n) {
            Windowcount1 += nums[right % n] - nums[left];
            minSwap = min(minSwap, Windowcount1);
            left++;
            right++;
        }

        return minSwap;
    }
};