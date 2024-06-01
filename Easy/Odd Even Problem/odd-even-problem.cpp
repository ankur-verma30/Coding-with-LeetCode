//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
    vector<int>res(27,0);
    
    for(char ch:s){
        res[ch-'a'+1]++;
    }
    
    int x=0,y=0;
    
    for(int i=1;i<27;i++){
        if(res[i]==0) continue;
        if(i%2!=0){
            if(res[i]%2!=0) y++;
        }
        else if(i%2==0){
            if(res[i]%2==0) x++;
        }
    }
        
        return ((x+y)%2==0)?"EVEN":"ODD";
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends