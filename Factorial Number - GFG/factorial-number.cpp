//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isFactorial(int N){
     
        if(N==1)
        return 1;
        int pro=1;
         for(int i=2;i<=N;i++){
              pro*=i;
             if(pro==N)
             return 1;
             else if(pro>N)
             break;
         }
         return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isFactorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends