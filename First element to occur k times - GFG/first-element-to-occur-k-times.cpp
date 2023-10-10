//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int firstElementKTime(int A[], int n, int k)
    
    {
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
        mp[A[i]]++;
        if(mp[A[i]]>=k)
        return A[i];
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends