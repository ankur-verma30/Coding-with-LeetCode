class Solution {
public:
    int K;
    int solve(int n) {
        if (n == 1)
            return 0;
        return (solve(n - 1) + K) % n;
    }
    int findTheWinner(int n, int k) {
        K = k;
        return solve(n) + 1;
    }
};