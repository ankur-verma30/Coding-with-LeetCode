class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int squaredMaxDiagonal = 0;
        for (const auto dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];

            int squaredDiagonalLength = length * length + width * width;
            int area = length * width;

             if (squaredDiagonalLength > squaredMaxDiagonal) {
                squaredMaxDiagonal = squaredDiagonalLength;
                maxArea = area;
            } 
            else if (squaredDiagonalLength == squaredMaxDiagonal) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};