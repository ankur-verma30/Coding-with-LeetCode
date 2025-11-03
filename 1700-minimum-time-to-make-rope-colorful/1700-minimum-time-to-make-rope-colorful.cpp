class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int len = colors.size(), time = 0;

        stack<pair<char, int>> st;
        st.push({colors[0], neededTime[0]});

        for (int i = 1; i < len; i++) {
            if (st.top().first == colors[i]) {
                pair<char, int> top = st.top();
                st.pop();
                time += min(top.second, neededTime[i]);

                st.push({colors[i], max(top.second, neededTime[i])});
            }
            else
            st.push({colors[i], neededTime[i]});
        }

        return time;
    }
};