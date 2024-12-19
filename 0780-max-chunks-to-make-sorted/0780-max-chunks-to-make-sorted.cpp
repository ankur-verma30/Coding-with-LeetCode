class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), count = 0, maxi = 0;

        for (int i = 0; i < n; i++) {
            maxi = max(arr[i], maxi);
            if (maxi == i)
                count++;
        }

        return count;
    }
};