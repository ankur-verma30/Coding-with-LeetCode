class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int def = target - num;
            if (m.find(def) != m.end()) {
                return {i, m[def]};
            }
            m[num] = i;
        }
        return {-1, -1};
    }
};