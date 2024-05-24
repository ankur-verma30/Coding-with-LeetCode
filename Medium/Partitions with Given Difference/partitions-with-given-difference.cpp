//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int mod=1e9+7;
    int solve(int i, int target, vector<int>&arr, vector<vector<int>>&dp){
        if(i==0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        
        dp[i][target]=solve(i-1, target, arr, dp)%mod;
        
        if(arr[i-1]<=target){
            dp[i][target]+=solve(i-1, target-arr[i-1], arr, dp);
            dp[i][target]%=mod;
        }
        
        return dp[i][target];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here4
          int total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        
        if(total<d || (total-d)%2==1) return 0;
        
        int target=(total-d)/2;
        
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        
        return solve(n, target, arr, dp);
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends