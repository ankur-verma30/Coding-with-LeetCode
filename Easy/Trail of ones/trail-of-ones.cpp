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
     if(n < 2) return 0;
        int f0=0,f1=1,f2;
        int ans = 1,mod = 1e9+7;
        for(int i=2;i<n;i++){
            f2 = (f0+f1)%mod;
            f0 = f1;
            f1 = f2;
            ans = ((ans*2)%mod + f2)%mod;
        }
        return ans;
    
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