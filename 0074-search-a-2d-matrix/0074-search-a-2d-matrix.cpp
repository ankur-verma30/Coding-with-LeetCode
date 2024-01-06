class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int low=0;
        int high=row*col-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int element=matrix[mid/col][mid%col];

            if(element==target)  return 1;
            
            else if(element<target)  low=mid+1;

            else high=mid-1;
        }
        return 0;
    }
};