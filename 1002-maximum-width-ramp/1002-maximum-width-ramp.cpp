class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] < nums[st.top()])
                st.push(i);
        }

        int maxWidth = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                maxWidth = max(maxWidth, i - st.top());
                st.pop();
            }
            if (st.empty())
                break;
        }

        return maxWidth;
    }
};