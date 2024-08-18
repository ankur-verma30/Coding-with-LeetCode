class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
          int n = nums.size();
        vector<int>result(n - k + 1);

        for (int i = 0; i <= n - k; i++) {
            bool isCons = true;
            int maxi = nums[i];

            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] + 1 != nums[j + 1]) {
                    isCons = false;
                    break;
                }
                maxi = max(maxi, nums[j + 1]);
            }

            
            if (isCons) {
                result[i] = maxi;
            } else {
                result[i] = -1;
            }
        }

        return result;
    }
};