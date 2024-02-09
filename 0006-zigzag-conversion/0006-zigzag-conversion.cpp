class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1)  return s;

        int len = s.length();
        int rows = numRows;
        int drows=rows-1;
        int col = 0;

        if (len % (2 * numRows - 2) == 0) 
            col = (len / (2 * numRows - 2)) * drows;
        else 
            col = (len / (2 * numRows - 2) + 1) *drows;

        vector<vector<char>> matrix(rows, vector<char>(col, '0'));

        int k = 0;
        while (k < len) {
            for (int j = 0; j < col && k < len; ++j) {
                for (int i = 0; i < rows && k < len; ++i) {
                    if (j % drows == 0 || j == 0) {
                        matrix[i][j] = s[k];
                        ++k;
                    } else {
                        matrix[drows - j % drows][j] = s[k];
                        ++k;
                        break;
                    }
                }
            }
        }

        string res;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] != '0') 
                    res += matrix[i][j];
            }
        }
        return res;
    }
}; 