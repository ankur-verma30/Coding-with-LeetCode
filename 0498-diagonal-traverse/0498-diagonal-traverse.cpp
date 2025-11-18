class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;

        int n=mat.size();
        int m=mat[0].size();

        vector<int>ans;
        int direction=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
           
        }

        for(const auto it:mp){
            vector<int>vec=it.second;
            if(direction==1) reverse(vec.begin(),vec.end());
            ans.insert(ans.end(),vec.begin(),vec.end());
             direction=1-direction;
        }

        return ans;
    }
};