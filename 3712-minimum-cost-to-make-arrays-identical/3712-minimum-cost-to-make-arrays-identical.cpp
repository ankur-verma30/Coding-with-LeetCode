class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        if (arr == brr)
            return 0;
        int n = arr.size();
        long long sumBeforeSwap = 0;

        for (int i = 0; i < n; i++) {
            sumBeforeSwap += abs(arr[i] - brr[i]);
        }

        long long sumAfterSwap = 0;

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for (int i = 0; i < n; i++) {
            sumAfterSwap += abs(arr[i] - brr[i]);
        }

        return min(sumBeforeSwap, sumAfterSwap + k);
    }
};