class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>positions;

        int row=mat.size();
        int col=mat[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                positions[mat[i][j]]={i,j};
            }
        }

        vector<int>rows(row+1,0),cols(col+1,0);

        for(int i=0;i<arr.size();i++){
            pair<int,int>temp=positions[arr[i]];
            int x=temp.first;
            int y=temp.second;

            rows[x]++;
            cols[y]++;
            if(rows[x]==col || cols[y]==row) return i;
        }

        return -1;
    }
};