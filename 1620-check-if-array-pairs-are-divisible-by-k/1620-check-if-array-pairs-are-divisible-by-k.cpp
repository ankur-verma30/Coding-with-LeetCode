class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if (k == 1)
            return true;
        unordered_map<int, int> mpp;

        for (auto& x : arr)
            mpp[(x % k + k) % k]++;

        for (auto& x : arr) {
            int rem = (x % k + k) % k;
            if (rem == 0) {
                if (mpp[rem] % 2 == 1)
                    return false;
            } else if (mpp[rem] != mpp[k - rem])
                return false;
        }

        return true;
    }
};