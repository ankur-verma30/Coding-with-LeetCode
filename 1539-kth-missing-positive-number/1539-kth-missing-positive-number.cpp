class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;
     (arr[mid] - mid > k)?high = mid: low = mid + 1;
    }
    return low + k; 
    }
};