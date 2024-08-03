class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
          vector<unordered_map<int, int>> Count(n);

    for (auto& x : pick) {
        int player = x[0];
        int color = x[1];
        Count[player][color]++;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (auto& pair : Count[i]) {
            if (pair.second > i) {
                count++;
                break;
            }
        }
    }

    return count;
        
    }
};