class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>winner,loser;
        unordered_map<int,int>player;

        for(int i=0;i<matches.size();i++){
            if(!(player.find(matches[i][0])!=player.end()))
                player[matches[i][0]]=0;  
        }

        for(int i=0;i<matches.size();i++){
            if(player.find(matches[i][1])!=player.end())
                player[matches[i][1]]++; 
                else
                player[matches[i][1]]=1; 
        }

        for(auto x:player){
            if(x.second==0) winner.push_back(x.first);
            if(x.second==1) loser.push_back(x.first);
        }

        sort(winner.begin(),winner.end());
        sort(loser.begin(),loser.end());

        return {winner,loser};

        
    }
};