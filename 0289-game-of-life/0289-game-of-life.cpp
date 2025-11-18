class Solution {
public:
    int liveCount(int r, int c, vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        int count = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nRow = r + i;
                int nCol = c + j;
                if (i == 0 && j==0)
                    continue;
                if (nRow >= 0 && nRow < row && nCol >= 0 && nCol < col &&
                    abs(board[nRow][nCol]) == 1)
                    count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int count = liveCount(i, j, board);
                if (board[i][j] == 0) {
                    if (count == 3)
                        board[i][j] = 2;
                } else {
                    if (count < 2 || count>3)
                        board[i][j] = -1;   
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] = (board[i][j] > 0) ? 1 : 0;
            }
        }
    }
};