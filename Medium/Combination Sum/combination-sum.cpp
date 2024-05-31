//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
   void solve(int index, vector<int>& A, int B, vector<int>& ds, vector<vector<int>>& ans) {
    if (B == 0) {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < A.size(); ++i) {
        if (i > index && A[i] == A[i - 1]) continue; // Skip duplicates
        if (A[i] > B) break; // No need to continue if the current element is greater than the remaining sum

        ds.push_back(A[i]);
        solve(i, A, B - A[i], ds, ans); // Not i + 1 because we can reuse the same element
        ds.pop_back();
    }


    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,A,B,ds,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends