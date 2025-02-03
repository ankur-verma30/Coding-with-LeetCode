class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int count=0;
        int first=-1,second=-1;

        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(start>first && end>second){
                first=start;
                count++;
            }
           second=max(second,end);
        }
        return count;
    }
};