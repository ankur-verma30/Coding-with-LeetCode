class Solution {
public:
    bool static compare(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int arrivalTime = times[targetFriend][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            DelayToChair;
        priority_queue<int, vector<int>, greater<int>> availableChair;
        int chairCount = 0;

        // sort the array
        sort(times.begin(), times.end(), compare);
        for (const auto& time : times) {
            int arrival = time[0];
            int depart = time[1];

            while (!DelayToChair.empty() && arrival >= DelayToChair.top()[0]) {
                availableChair.push(DelayToChair.top()[1]);
                DelayToChair.pop();
            }

            int CurrentChairNo;
            if (!availableChair.empty()) {
                CurrentChairNo = availableChair.top();
                availableChair.pop();
            } else {
                CurrentChairNo = chairCount;
                chairCount++;
            }
            if (arrivalTime == arrival)
                return CurrentChairNo;
            DelayToChair.push({depart, CurrentChairNo});
        }

        return 0;
    }
};