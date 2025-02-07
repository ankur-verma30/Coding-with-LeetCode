class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       unordered_map<int,int>colorCount,ballColor;

        vector<int>res;
       for(const auto &query:queries){
        int ball=query[0];
        int color=query[1];

        //ball already colored;
        if(ballColor.find(ball)!=ballColor.end()){
            if(color==ballColor[ball]) {
                 res.push_back(colorCount.size());
                 continue;
            }
            else{
                colorCount[ballColor[ball]]--;
                if(colorCount[ballColor[ball]]==0) colorCount.erase(ballColor[ball]);
                 colorCount[color]++; 
            }
        }
        else  colorCount[color]++;
            ballColor[ball]=color;
         res.push_back(colorCount.size());
        } 

       return res;
    }
};