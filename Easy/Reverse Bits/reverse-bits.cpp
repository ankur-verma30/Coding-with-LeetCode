//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long num) {
       unsigned long long reversedNum = 0;
    for (int i = 0; i < 32; i++) {
        reversedNum <<= 1;          
        reversedNum |= num & 1;     
        num >>= 1;                  
    }
    return reversedNum;
   
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends