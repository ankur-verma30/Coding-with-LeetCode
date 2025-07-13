class Solution {
public:
    bool isValid(int n, vector<int>& position, int distance, int m) {
        int prev = position[0], countBalls = 1;

        for (int i = 1; i < n; i++) {
            int curr = position[i];
            if (curr - prev >= distance)
                countBalls++, prev = curr;

            if (countBalls == m)
                break;
        }
        return countBalls == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int low = 1, high = position[n-1]-position[0];
        int maxForce = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(n, position, mid, m)) {
                maxForce = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return maxForce;
    }
};