class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        stack<int> st;
        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i])
                st.pop();
            if (st.empty()) {
                ans[i] = prices[i];
                st.push(prices[i]);
            } else {
                ans[i] = prices[i] - st.top();
                st.push(prices[i]);
            }
        }
        return ans;
    }
};