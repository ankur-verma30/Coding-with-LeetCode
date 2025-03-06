class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int order=grid.size();
    vector<int>freq((order*order)+1,0);
   
    
    for(int i=0;i<order;i++){
        for(int j=0;j<order;j++){
            freq[grid[i][j]]++;
        }
    }

    int repeated=0,missing=0;


    for(int i=1;i<freq.size();i++){
        if(freq[i]==2) repeated=i;
        else if(freq[i]==0) missing=i;
    }

    return {repeated,missing};
    }
};