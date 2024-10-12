class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2)
                continue;
                 int val = nums[i];
            int mini = INT_MAX;
            bool found = false;
            for (int bits = 0; bits <= 30; bits++) {
                if (((val >> bits) & 1) == 1) {
                    int temp = val & ~(1 << bits);
                    if (temp < 0)
                        continue;
                    if ((temp | (temp + 1)) == val) {
                        if (temp < mini) {
                            mini = temp;
                            found = true;
                        }
                    }
                }
            }
            ans[i] = found ? mini : -1;
        }
        return ans;
    }
};