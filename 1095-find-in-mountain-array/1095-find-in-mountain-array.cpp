/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray& arr) {
        int low = 1, high = arr.length() - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int midVal = arr.get(mid);

            if (midVal > arr.get(mid - 1) && midVal > arr.get(mid + 1))
                return mid;
            else if (midVal < arr.get(mid + 1))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int binarySearchAsc(MountainArray& arr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = arr.get(mid);

            if (val == target)
                return mid;
            else if (val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int binarySearchDesc(MountainArray& arr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = arr.get(mid);

            if (val == target)
                return mid;
            else if (val > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int peak = findPeak(mountainArr);
        int leftResult = binarySearchAsc(mountainArr, target, 0, peak);
        if (leftResult != -1)
            return leftResult;
        return binarySearchDesc(mountainArr, target, peak + 1,
                                mountainArr.length() - 1);
    }
};
