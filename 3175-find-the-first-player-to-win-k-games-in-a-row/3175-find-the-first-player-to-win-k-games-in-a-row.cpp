
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int currentWinCount = 0;
        int currentWinner = skills[0];

        for (int i = 1; i < n; ++i) {
            if (skills[i] > currentWinner) {
                currentWinner = skills[i];
                currentWinCount = 1;
            } else
                currentWinCount++;

            if (currentWinCount == k)
                break;
        }

        for (int i = 0; i < n; ++i) {
            if (skills[i] == currentWinner) {
                return i;
            }
        }

        return -1;
    }
};
