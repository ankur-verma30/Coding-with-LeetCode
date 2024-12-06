class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> st;
        int count = 0, sum = 0;

        for (int i = 0; i < banned.size(); i++)
            st.insert(banned[i]);

        for (int i = 1; i <= n; i++) {
            if (st.count(i) <= 0) {
                sum += i;
                if (sum > maxSum)
                    break;
                count++;
            }
        }

        return count;
    }
};