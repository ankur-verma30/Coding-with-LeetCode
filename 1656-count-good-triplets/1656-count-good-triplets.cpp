class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                  int canA = abs(arr[i] - arr[j]);
                if (canA > a)
                    continue;
                for (int k = j + 1; k < n; k++) {
                    int canB = abs(arr[j] - arr[k]);
                    int canC = abs(arr[k] - arr[i]);
                    if ( canB <= b && canC <= c)
                        count++;
                }
            }
        }
        return count;
    }
};