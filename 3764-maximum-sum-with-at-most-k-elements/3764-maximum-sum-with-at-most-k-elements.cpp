class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int row=grid.size();
        int col=grid[0].size();

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<row;i++){
            int limit=limits[i];
            priority_queue<int,vector<int>,greater<int>>temp;

            for(int j=0;j<col;j++){
                temp.push(grid[i][j]);
                if(temp.size()>limit) temp.pop();
            }

            while(!temp.empty()){
                pq.push(temp.top());
                temp.pop();
                if(pq.size()>k) pq.pop();
            }
        }

        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }

        return sum;
    }
};