class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), maxLen = 0;

        for (int index = 1; index < n - 1; index++) {
            if (arr[index] > arr[index - 1] && arr[index] > arr[index + 1]){       
                 int currLeft = arr[index];
            int leftLen = 0, rightLen = 0;
            for (int i = index - 1; i >= 0; i--) {
                if (arr[i] < currLeft) {
                    currLeft = arr[i];
                    leftLen = index - i;
                } else
                    break;
            }
            // go to right
            int currRight = arr[index];
            for (int i = index + 1; i < n; i++) {
                if (arr[i] < currRight) {
                    currRight = arr[i];
                    rightLen = i - index;
                } else
                    break;
            }
            maxLen = max(maxLen, leftLen + rightLen + 1);
            index+=rightLen;
            }
            
               
        }

        return maxLen;
    }
};