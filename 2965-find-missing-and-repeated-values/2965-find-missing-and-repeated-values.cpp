class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_map<int,int>mp;
    int a=0,b=0;

    int order=grid.size();
    
    for(int i=0;i<order;i++){
        for(int j=0;j<order;j++){
            mp[grid[i][j]]++;
        }
    }

    for(auto x:mp){
        if(x.second==2) a=x.first;
    }


    for(int i=1;i<=order*order;i++){
        if(!mp.count(i)){
            b=i;
            break;
        }
    }

    return {a,b};
    }
};