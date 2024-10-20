//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int source,vector<vector<int>>&adj,vector<int>&visited){
        visited[source]=1;
        queue<pair<int,int>>q;
        q.push({source,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto adjacent:adj[node]){
                if(!visited[adjacent]){
                    visited[adjacent]=1;
                    q.push({adjacent,node});
                }
                else{
                    if(adjacent!=parent) return true; 
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>> adj) {
        int vertex=adj.size();
      vector<int>visited(vertex,0);
      
      for(int i=0;i<vertex;i++){
          if(!visited[i]){
              if(detectCycle(i,adj,visited)) return true;
          }
      }
      return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends