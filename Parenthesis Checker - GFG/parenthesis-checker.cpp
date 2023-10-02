//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
      stack<char> st;
      for(int i=0; i<x.length();i++){
          
          if(x[i]=='{' || x[i]=='[' || x[i]=='(')
          st.push(x[i]);
          else {        
          if(st.empty())
          return false;
          
          char t=st.top();
          if((x[i]==']' && t=='[') ||(x[i]==')' && t=='(')|| x[i]=='}' && t=='{')
          st.pop();
          else 
          return false;
      }
      }
      return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends