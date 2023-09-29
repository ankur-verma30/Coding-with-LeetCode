

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        int score = 0;

        for (const string& op : operations) {
            if (op == "C") {
                if (!st.empty()) {
                    sum -= st.top();
                    st.pop();
                }
            } else if (op == "D") {
                if (!st.empty()) {
                    int prev = st.top();
                    st.push(prev * 2);
                    sum += prev * 2;
                }
            } else if (op == "+") {
                if (st.size() >= 2) {
                    int prev1 = st.top();
                    st.pop();
                    int prev2 = st.top();
                    st.push(prev1);
                    st.push(prev1 + prev2);
                    sum += (prev1 + prev2);
                }
            } else {
                score = stoi(op);
                st.push(score);
                sum += score;
            }
        }

        return sum;
    }
};
