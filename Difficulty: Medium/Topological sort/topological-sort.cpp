//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
      
      int vertex=adj.size();
      vector<int>indegree(vertex,0);
      queue<int>q;
      
      for(int i=0;i<vertex;i++){
          for(auto x:adj[i]) indegree[x]++;
      }
      
      
        vector<int>ans;
        int n=indegree.size();
      for(int i=0;i<n;i++){
          if(indegree[i]==0)q.push(i);
      }
      
      
      while(!q.empty()){
          int element=q.front();
          q.pop();
          
          ans.push_back(element);
          
          for(auto it:adj[element]) {
              indegree[it]--;
              if(indegree[it]==0) q.push(it);
          }
          
      }
      
      return ans;
      
        
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends