class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                arr[i] = -1;
        }

        int sum = 0, length = 0;

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0)
                length = max(length, i + 1);
            else if (mpp.find(sum) != mpp.end())
                length = max(length, i - mpp[sum]);
            else
                mpp[sum] = i;
        }

        return length;
    }
};