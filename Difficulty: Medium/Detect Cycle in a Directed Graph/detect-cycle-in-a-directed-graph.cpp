//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
      vector<int>indegree(V,0);
      
      for(int i=0;i<adj.size();i++){
          for(const auto &x:adj[i]) indegree[x]++;
      }
      
      queue<int>q;
      
      for(int i=0;i<indegree.size();i++){
          if(indegree[i]==0) q.push(i);
      }
      
      vector<int>topo;
     while(!q.empty()){
      int ele=q.front();
      q.pop();
      topo.push_back(ele);
      for(const auto &x:adj[ele]){
          indegree[x]--;
          if(indegree[x]==0) q.push(x);
      }
  }
  
  return !(topo.size()==V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends