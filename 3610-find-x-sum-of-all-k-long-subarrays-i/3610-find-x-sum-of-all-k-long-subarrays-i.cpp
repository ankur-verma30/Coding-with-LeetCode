class Solution {
public:
    int solve(vector<int>& temp, int x) {
        map<int, int> freq;
        int n = temp.size();
        for (int i = 0; i < n; i++) {
            freq[temp[i]]++;
        }

        vector<pair<int, int>> vec;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            vec.push_back(make_pair(it->first, it->second));
        }

        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        });
        int count = 0, sum = 0;
        for (auto y : vec) {
            if (count == x)
                break;
            sum += (y.first * y.second);
            count++;
        }

        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int size = nums.size();
        int ansSize = size - k + 1;
        vector<int> res;

         for (int i = 0; i < ansSize; i++) {
            vector<int> temp(nums.begin() + i, nums.begin() + i + k);
            int sum = solve(temp, x);
            res.push_back(sum);
        }

        return res;
    }
};