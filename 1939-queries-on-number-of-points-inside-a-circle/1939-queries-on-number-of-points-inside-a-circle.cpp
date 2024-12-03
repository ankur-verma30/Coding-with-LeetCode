class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points,
                            vector<vector<int>>& queries) {
        vector<int> res;

        for (const auto& query : queries) {
            int xCenter = query[0];
            int yCenter = query[1];
            int radius = query[2];

            int count = 0;

            for (const auto& point : points) {
                int xCordinate = point[0];
                int yCordinate = point[1];

                if (((xCenter-xCordinate)*(xCenter-xCordinate))+((yCenter-yCordinate)*(yCenter-yCordinate))<=(radius*radius)) 
                    count++;
            }

            res.push_back(count);
        }

        return res;
    }
};