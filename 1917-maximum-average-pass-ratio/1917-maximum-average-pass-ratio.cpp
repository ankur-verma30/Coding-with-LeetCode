class Solution {
public:
    double passDiff(int pass, int total) {
         return ((pass + 1) / static_cast<double>(total + 1)) - (pass / static_cast<double>(total));
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         priority_queue<pair<double, pair<int, int>>> pq;

        for (const auto& it : classes) {
            int pass = it[0];
            int total = it[1];
            double diff = passDiff(pass, total);
            pq.push({diff, {pass, total}});
        }

        while (extraStudents--) {
            auto it = pq.top();
            pq.pop();
            int pass = it.second.first;
            int total = it.second.second;
            double diff = passDiff(pass + 1, total + 1);
            pq.push({diff, {pass + 1, total + 1}});
        }

        double totalRatio = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            int pass = it.second.first;
            int total = it.second.second;
            double ratio = static_cast<double>(pass) / total;
            pq.pop();
            totalRatio += ratio;
        }

        return totalRatio / classes.size();
    }
};