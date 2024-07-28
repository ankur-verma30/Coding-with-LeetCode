//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    vector<char>vec(26,0);
	    string str="";
	    
	    for(int i=0;i<S.length();i++){
	       if(vec[S[i]-'a']==0) 
	       vec[S[i]-'a']++;
	       else continue;
	    }
	    
	    for(int i=0;i<S.length();i++){
	        if(vec[S[i]-'a']==1){
	            str+=S[i];
	            vec[S[i]-'a']=0;
	        }
	        if(vec[S[i]-'a']==0) continue;
	    }
	    
	    return str;
	}
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends