class Solution {
public:
    void dfs(int paramRow, int paramCol, vector<vector<char>>& board,
             vector<vector<int>>& visited, int del[]) {
        visited[paramRow][paramCol] = 1;
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < 4; i++) {
            int nRow = paramRow + del[i];
            int nCol = paramCol + del[i + 1];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                visited[nRow][nCol] != 1 && board[nRow][nCol] == 'O')
                dfs(nRow, nCol, board, visited, del);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int del[] = {-1, 0, 1, 0, -1};
        // traversing rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board, visited, del);
            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board, visited, del);
        }

        // traversing columns
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board, visited, del);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board, visited, del);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};