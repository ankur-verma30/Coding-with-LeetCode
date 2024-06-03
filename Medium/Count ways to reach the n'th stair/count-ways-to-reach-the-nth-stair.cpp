//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        int mod=1e9+7;
        int prev0=0;
        int prev=1;
        
        if(n<=1) return n;
        
        for(int i=2;i<=n+1;i++){
            int curr=(prev0+prev)%mod;
            prev0=prev;
            prev=curr;
        }
        
        return prev%mod;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends