//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
#define ll long long
const ll mod = 1e9 + 7;

// Function to perform modular exponentiation
ll modExp(ll base, ll exp, ll m) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        exp = exp / 2;
    }
    return result;
}

int numberOfConsecutiveOnes(int n) {
    if (n == 0) return 0; // No strings with consecutive 1's if length is 0
    if (n == 1) return 0; // No strings with consecutive 1's if length is 1

    ll total = modExp(2, n, mod); // Calculate 2^n % mod using modular exponentiation

    ll dp[n + 1];
    dp[0] = 1; // Empty string
    dp[1] = 2; // "0", "1"

    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }

    ll noConsecutiveOnes = dp[n];
    ll result = (total - noConsecutiveOnes + mod) % mod; // Ensure non-negative result

    return result;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends