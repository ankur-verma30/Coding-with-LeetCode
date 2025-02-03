class Solution {
public:
    static bool compare(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();
        int count=0;

        vector<pair<int,int>>interval;
        for(int i=0;i<n;i++){
            interval.push_back({intervals[i][0],intervals[i][1]});
        }

        sort(interval.begin(),interval.end(),compare);
        int freeTime=interval[0].second;

        for(int i=1;i<n;i++){
            int start=interval[i].first;
            int end=interval[i].second;
            if(freeTime>start) count++;
            else freeTime=end;
        }

        return count;
    }
};