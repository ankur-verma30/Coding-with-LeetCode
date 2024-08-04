class neighborSum {
    vector<vector<int>>grid;
    int n;
public:
    
    neighborSum(vector<vector<int>>& grid):grid(grid) {
        n=grid.size();
    }

    pair<int, int> position(int value) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == value) return {i, j};

            }
        }
        return {-1, -1}; 
    }

    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    
    int adjacentSum(int value) {
         auto [x, y] = position(value);
        int sum = 0;
        int changeInX[] = {-1, 1, 0, 0}; 
        int changeInY[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int newX = x + changeInX[i];
            int newY = y + changeInY[i];
            if (isValid(newX, newY))  sum += grid[newX][newY];


        }

        return sum;
        
    }
    
    int diagonalSum(int value) {
          auto [x, y] = position(value);
        int sum = 0;
         int changeInX[] ={-1, -1, 1, 1}; 
        int changeInY[] = {-1, 1, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int newX = x + changeInX[i];
            int newY = y + changeInY[i];
            if (isValid(newX, newY))  sum += grid[newX][newY];

        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */