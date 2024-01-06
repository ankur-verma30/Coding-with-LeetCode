class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int order=mat.size();
        // if(order==1)  return mat[0][0];

        int sum=0;

        for(int i=0;i<order;i++){
            sum+=mat[i][i];
            sum+=mat[i][order-i-1];
        }
        if(order & 1)
        sum-=mat[order/2][order/2];

        return sum;
        

    }
};