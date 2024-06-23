class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(),
                                                               nums.end());
        priority_queue<int> maxHeap(nums.begin(), nums.end());

        double minAvg = INT_MAX;
        int n = nums.size() / 2;

        for (int i = 0; i < n; ++i) {
            double minElement = minHeap.top();
            double maxElement = maxHeap.top();

            minHeap.pop();
            maxHeap.pop();

            double avg = (minElement + maxElement) / 2.0;

            minAvg = min(minAvg, avg);
        }

        return minAvg;
    }
};