//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string ans,temp;
       for(int i=0;i<s.length();i++){
           if(s[i]=='.'){
               reverse(temp.begin(),temp.end());
               ans+=temp+".";
               temp="";
           }
           else{
               temp.push_back(s[i]);
           }
       }
       reverse(temp.begin(),temp.end());
       
       return ans+temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends