class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (st.count(nums[i]))
                return nums[i];
            st.insert(nums[i]);
        }
        return -1;
    }
};