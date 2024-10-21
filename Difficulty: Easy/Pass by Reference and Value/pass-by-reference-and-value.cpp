//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int>solve(vector<int>&res,int a,int&b){
        a+=1;
        b+=2;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
    vector<int> passedBy(int a, int &b) {
      vector<int>res;
       solve(res,a,b);
       return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        Solution obj;
        vector<int> ans = obj.passedBy(a, b);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends