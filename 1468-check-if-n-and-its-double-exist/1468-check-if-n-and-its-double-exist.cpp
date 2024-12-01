class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < arr.size(); i++)
            mpp[arr[i]] = i;

        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];

            if (mpp.find(2 * val) != mpp.end() && mpp[2 * val] != i)
                return true;
        }

        return false;
    }
};