//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dataTypeSize(string str) {
        int a=3;
        char ch='a';
        long l=2;
        float f=3;
        double d=4;
       if(str=="Character") return sizeof(char);
       else if(str=="Integer") return sizeof(int);
       else if(str=="Long") return sizeof(long);
       else if(str=="Float") return sizeof(float);
       else if(str=="Double") return sizeof(double);
       else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends