//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        
        if(N==0)
        return -1;
      
    if ((N & (N - 1)) == 0) {
       
        int position = 0;
        while (N > 0) {
            N = N >> 1;
            position++;
        }
        return position;
    }

    
    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends