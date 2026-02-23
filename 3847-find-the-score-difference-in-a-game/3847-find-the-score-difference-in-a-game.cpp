class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int player1 = 0, player2 = 0;
        bool activePlayer1 = true, activePlayer2 = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                activePlayer2 = !activePlayer2, activePlayer1 = !activePlayer1;
            }
            if ((i + 1) % 6 == 0) {
                activePlayer2 = !activePlayer2, activePlayer1 = !activePlayer1;
            }
            if (activePlayer1)
                player1 += nums[i];
            else
                player2 += nums[i];
            // cout<<"player1 "<<player1<<" "<<"player2 "<<player2<<endl;
        }

        return player1 - player2;
    }
};