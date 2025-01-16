class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        long long pro = 1;
        bool isZero = false;
        int zeroCount = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                isZero = true;
                zeroCount++;
                continue;

            } else
                pro *= arr[i];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (isZero) {
                if (arr[i] != 0)
                    res[i] = 0;
                else if (arr[i] == 0 && zeroCount <= 1)
                    res[i] = pro;
                else if (arr[i] == 0 && zeroCount > 1)
                    res[i] = 0;
            } else
                res[i] = pro / arr[i];
        }

        return res;
    }
};