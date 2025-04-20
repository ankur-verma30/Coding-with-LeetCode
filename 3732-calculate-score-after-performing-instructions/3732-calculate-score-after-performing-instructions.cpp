class Solution {
public:
    long long calculateScore(vector<string>& instructions,
                             vector<int>& values) {
        int n = values.size();
        long long score = 0;

        vector<bool> visited(n, 0);
        for (int i = 0; i < n;) {
            if (i < 0 || i >= n || visited[i])
                break;
            visited[i] = 1;
            (instructions[i] == "add") ? score += values[i],
                i++                    : i += values[i];
        }
        return score;
    }
};