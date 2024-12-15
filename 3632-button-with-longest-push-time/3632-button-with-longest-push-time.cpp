class Solution {
public:
   
    int buttonWithLongestTime(vector<vector<int>>& events) {
       int startTime=0,maxTime=INT_MIN,ansIndex=events.size();

       for(const auto &event:events){
        int index=event[0];
        int time=event[1];
            int  diff=time-startTime;
            startTime=time;
            if(diff==maxTime){
                if(index<ansIndex) ansIndex=index;
                    maxTime=diff; 
            }
            else if(diff>maxTime){
                maxTime=diff;
                ansIndex=index;
            }
       }

       return ansIndex;

      
    }
};