class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row=accounts.size();
        int col=accounts[0].size();

        int maxi=-1;

        for(int i=0;i<row;i++){
            int sum=0;
            for(int j=0;j<col;j++){
                sum+=accounts[i][j];
                
            }
            if(maxi<sum) maxi=sum;
        }

        return maxi;

    }
};