class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {

        vector<int> ans;
        int n = arr.size();

        for (int end = n - 1; end > 0; end--) {

            int maxIndex = 0;

            for (int i = 1; i <= end; i++) {
                if (arr[i] > arr[maxIndex])
                    maxIndex = i;
            }

            // already in correct place
            if (maxIndex == end)
                continue;

            // bring maximum to front
            if (maxIndex != 0) {
                reverse(arr.begin(), arr.begin() + maxIndex + 1);
                ans.push_back(maxIndex + 1);
            }

            // move maximum to its final position
            reverse(arr.begin(), arr.begin() + end + 1);
            ans.push_back(end + 1);
        }

        return ans;
    }
};