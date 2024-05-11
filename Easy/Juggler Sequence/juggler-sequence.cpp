//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
            vector< long long>res;
            res.push_back(n);
            
            while(n>0){
                if(n==1) break;
                
                if( n & 1){
                    n=sqrt(pow(n,3));
                    res.push_back(n);
                }
                else{
                    n=sqrt(n);
                    res.push_back(n);
                }
            }
            return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends