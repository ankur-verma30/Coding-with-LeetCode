class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mpp;
        int row=edges.size();
        int col=edges[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) mpp[edges[i][j]]++;
        }
    int val=0;
    for(auto & x:mpp){
        if(x.second==row){
            val=x.first;
            break;
        };
    }
    return val;
    }
};