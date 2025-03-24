class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
          if (meetings.empty()) {
            return days;
        }
        
        sort(meetings.begin(), meetings.end());
        
        
        int totalDays = 0;
        int Start = meetings[0][0];
        int End = meetings[0][1];
        
        for (const auto& meeting : meetings) {
            if (meeting[0] <= End) {
                End = max(End, meeting[1]);
            } else {
                totalDays += (End - Start + 1);
                Start = meeting[0];
                End = meeting[1];
            }
        }
        totalDays += (End - Start + 1);
        
        return days - totalDays;
    }
};