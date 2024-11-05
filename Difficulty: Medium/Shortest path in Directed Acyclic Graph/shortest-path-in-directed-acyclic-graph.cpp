//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void topoSort(int index,vector<vector<pair<int,int>>>&adj,vector<int>&visited,stack<int>&st){
      visited[index]=1;
      
      for(auto it:adj[index]){
          int v=it.first;
          if(visited[v]!=1){
              
              topoSort(v,adj,visited,st);
          }
      }
      st.push(index);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int>visited(V,0);
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            
            adj[u].push_back({v,weight});
        }
        
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(visited[i]!=1){
                topoSort(i,adj,visited,st);
            }
        }
        
        vector<int>distance(V,INT_MAX);
        
        distance[0]=0;
        
        while(!st.empty()){
            int element=st.top();
            st.pop();
            //read all the adjacent nodes
            for(auto it:adj[element]){
                int adjacent=it.first;
                int weight=it.second;
                //distance should not be int max otherwise adding weight to int_Max will lead to 
                if(distance[element] != INT_MAX && distance[element]+weight<distance[adjacent]){
                    distance[adjacent]= weight+distance[element];
                }
            }
        }
        
        
        for(int i=0;i<V;i++){
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends