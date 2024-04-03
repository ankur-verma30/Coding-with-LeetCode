//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long sumSubstrings(string s){
        int MOD=1e9+7;
        
      long long result = 0; // Use long long to prevent overflow
    long long multiplier = 1; // Multiplier for the current position
    
    for (int i = s.length() - 1; i >= 0; --i) {
        // Calculate contribution of current digit to the sum
        result = (result + (s[i] - '0') * multiplier * (i + 1)) % MOD;
        
        // Update multiplier for next position
        multiplier = (multiplier * 10 + 1) % MOD;
    }
    
    return result;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends