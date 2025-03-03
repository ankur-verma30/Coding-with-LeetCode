class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size(), sum = 0, left = 0, count = 0;

        for (int right = 0; right < n; right++) {
            if (right >= k) {
                int avg = sum / k;
                if (avg >= threshold)
                    count++;
                sum -= arr[left];
                left++;
            }
            sum += arr[right];
        }

        if (sum / k >= threshold)
            count++;

        return count;
    }
};