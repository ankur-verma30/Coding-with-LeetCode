class Solution {
public:
    bool canPlace(const vector<int>& start, int d, int minDiff) {
        int n = start.size();
        int prev = start[0];
        for (int i = 1; i < n; ++i) {
            int candidate = max(prev + minDiff, start[i]);
            if (candidate > start[i] + d)
                return false;
            prev = candidate;
        }

        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int low = 0, high = INT_MAX;
        int result = 0;

        while (low <= high) {
            long mid = low+(high-low) / 2;
            if (canPlace(start, d, mid)) {
                result =(int)mid;  
                low = mid + 1; 
            } else  high = mid - 1;
            
        }

        return (int)result;
    }
};