//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>>adj(N);
        
        for(int i=0;i<edges.size();i++){
           int first=edges[i][0];
           int second=edges[i][1];
           adj[first].push_back(second);
           adj[second].push_back(first);
        }
        
        vector<int>distance(N,INT_MAX);
        queue<int>q;
        
        distance[src]=0;
        q.push(src);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
           
            
            for(auto it:adj[curr]){
                if(distance[curr]+1< distance[it]){
                    distance[it]=distance[curr]+1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<distance.size();i++){
            if(distance[i]==INT_MAX) distance[i]=-1;
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends