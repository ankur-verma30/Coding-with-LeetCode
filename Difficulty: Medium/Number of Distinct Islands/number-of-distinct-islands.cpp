//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited,
    vector<pair<int,int>>&temp,int baseRow,int baseCol){
        int n=grid.size();
       int m=grid[0].size();
        visited[row][col]=1;
        temp.push_back({row-baseRow,col-baseCol});
        
        int del[]={-1,0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nRow=row+del[i];
            int nCol=col+del[i+1];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 && visited[nRow][nCol]!=1)
            dfs(nRow,nCol,grid,visited,temp,baseRow,baseCol);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
       set<vector<pair<int,int>>>st;
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               
               if(grid[i][j]==1 && visited[i][j]!=1){
                   vector<pair<int,int>>temp;
                   dfs(i,j,grid,visited,temp,i,j);
                   st.insert(temp);
               }
           }
       }
       
       return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends