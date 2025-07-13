class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int pSize = players.size(), tSize = trainers.size(), j = 0;

        int playerCount = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        for (int i = 0; i < pSize && j < tSize; i++) {
            while (j < tSize && players[i] > trainers[j])
                j++;

            if (j < tSize && players[i] <= trainers[j]) {
                playerCount++;
                j++;
            }
        }

        return playerCount;
    }
};