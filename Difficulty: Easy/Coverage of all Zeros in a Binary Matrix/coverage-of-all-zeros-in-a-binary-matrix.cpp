//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
     int row = matrix.size();
    int col = matrix[0].size();
    int total = 0;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == 0) {
                // Check left
                for (int k = j - 1; k >= 0; --k) {
                    if (matrix[i][k] == 1) {
                        total++;
                        break;
                    }
                    if (matrix[i][k] == 0) {
                        break;
                    }
                }
                // Check right
                for (int k = j + 1; k < col; ++k) {
                    if (matrix[i][k] == 1) {
                        total++;
                        break;
                    }
                    if (matrix[i][k] == 0) {
                        break;
                    }
                }
                // Check up
                for (int k = i - 1; k >= 0; --k) {
                    if (matrix[k][j] == 1) {
                        total++;
                        break;
                    }
                    if (matrix[k][j] == 0) {
                        break;
                    }
                }
                // Check down
                for (int k = i + 1; k < row; ++k) {
                    if (matrix[k][j] == 1) {
                        total++;
                        break;
                    }
                    if (matrix[k][j] == 0) {
                        break;
                    }
                }
            }
        }
    }

    return total;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends