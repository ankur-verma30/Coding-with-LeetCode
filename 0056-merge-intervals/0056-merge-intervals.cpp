class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        int first=intervals[0][0],second=intervals[0][1]; 

        for (int i = 1; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start<=second){
                second=max(second,end);
            }
            else{
                ans.push_back({first,second});
                first=start;
                second=end;
            }
        }    
        ans.push_back({first,second});
        return ans;
    }
};