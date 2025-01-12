class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int totalWater = 0, leftMax = 0, RightMax = 0, right = n - 1, left = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= leftMax)
                    leftMax = arr[left];
                else
                    totalWater += (leftMax - arr[left]);
                left++;
            } else {
                if (arr[right] >= RightMax)
                    RightMax = arr[right];
                else
                    totalWater += (RightMax - arr[right]);
                right--;
            }
        }
        return totalWater;
    }
};