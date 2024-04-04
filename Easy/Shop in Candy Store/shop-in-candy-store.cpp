//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int mini=0,buy=0;
        int offer=N-1;
        
        while(buy<=offer){
            mini+=candies[buy];
            buy++;
            offer-=K;
        }
        
        int maxi=0;
        buy=N-1,offer=0;
        
        while(offer<=buy){
            maxi+=candies[buy];
            buy--;
            offer+=K;
        }
        return {mini,maxi};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends