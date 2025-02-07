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
            int prevColor=ballColor[ball];
            if(color!=prevColor){
                colorCount[prevColor]--;
                if(colorCount[prevColor]==0) colorCount.erase(prevColor);
                 colorCount[color]++;
                 cout<<"map size "<<colorCount.size()<<endl;
                
            }
            else {
                 res.push_back(colorCount.size());
                 continue;
            }
        }
        else {
             colorCount[color]++;
             cout<<"map size "<<colorCount.size()<<endl;
        }
            ballColor[ball]=color;
         res.push_back(colorCount.size());
       
        } 

       return res;
    }
};