class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        
       int n = original.size();
        int mins = bounds[0][0],maxs = bounds[0][1];
        for(int i = 1;i<n;i++){
            int diff = original[i] - original[i-1];
            
            mins = max(mins + diff, bounds[i][0]);
            maxs = min(maxs + diff, bounds[i][1]);

            if(mins >maxs)return 0;
            
        }
        return maxs - mins +1 ;  
    }
};