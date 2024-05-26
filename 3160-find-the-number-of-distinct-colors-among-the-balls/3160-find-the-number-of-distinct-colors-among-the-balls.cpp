class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls;
        unordered_map<int, int> count;
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int val = queries[i][0];
            int col = queries[i][1];

            if (balls.find(val) == balls.end()) {
                balls[val] = col;
                count[col]++;
            } else {
                int current = balls[val];
                count[current]--;
                if (count[current] == 0)
                    count.erase(current);
                balls[val] = col;
                count[col]++;
            }
            ans.push_back(count.size());
        }

        return ans;
    }
};