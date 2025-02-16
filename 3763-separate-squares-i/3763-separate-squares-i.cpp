class Solution {
public:
    bool LowerHalfLargerArea(vector<vector<int>>& squares, double yLine) {
        double lowerArea = 0, upperArea = 0;

        for (const auto& square : squares) {
            double bottomY = square[1];
            double side = square[2];
            double topY = bottomY + side;

            if (topY <= yLine)
                lowerArea += (side * side);
            else if (bottomY >= yLine)
                upperArea += (side * side);
            else {
                double below = yLine - bottomY;
                double above = topY - yLine;
                lowerArea += (below * side);
                upperArea += (above * side);
            }
        }
        return lowerArea >= upperArea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double minY = squares[0][1];
        double maxY = squares[0][1] + squares[0][2];

        for (const auto& square : squares) {
            minY = min(minY, square[1] * 1.0);
            maxY = max(maxY, (square[1] + square[2]) * 1.0);
        }

        double precision = 1e-5;
        while (maxY - minY > precision) {
            double midY = minY + (maxY - minY) / 2;
            if (LowerHalfLargerArea(squares, midY))
                maxY = midY;
            else
                minY = midY;
        }

        return minY;
    }
};