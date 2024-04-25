//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
       if (n < 3 || m < 3) // If the matrix is smaller than 3x3, no hourglasses can be formed
        return -1;

    int maxSum = INT_MIN;

    for (int i = 0; i <= n - 3; ++i) {
        for (int j = 0; j <= m - 3; ++j) {
            int sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + 
                      mat[i + 1][j + 1] + 
                      mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends