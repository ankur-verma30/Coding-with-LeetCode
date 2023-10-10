//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
        int count=2;
       
       if(N==1)
       return 0;
       
        for(int i=2;i<=sqrt(N);i++)
       {
           if(N%i==0)
           count++;
           if(count>2)
           return 0;
       }
     return (count==2)?1:0;
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
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends