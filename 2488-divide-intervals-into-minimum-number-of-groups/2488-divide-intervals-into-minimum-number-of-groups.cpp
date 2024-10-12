class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = intervals.size();
        
        for (auto& time : intervals) {
            mini = min(mini, time[0]);
            maxi = max(maxi, time[1]);
        }

        vector<int> prefix(maxi + 2, 0);
        for (auto& time : intervals) {
            prefix[time[0]]++;
            prefix[time[1] + 1]--;
        }
        int maxOverlaps = 0, sum = 0;
        for (int i = mini; i < maxi + 2; i++) {
            sum += prefix[i];
            maxOverlaps = max(maxOverlaps, sum);
        }

        return maxOverlaps;
    }
};