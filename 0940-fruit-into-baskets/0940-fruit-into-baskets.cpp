class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         unordered_map<int, int> mpp;

        int n = fruits.size(), left = 0, maxLength = 0;

        for (int right = 0; right < n; right++) {
             mpp[fruits[right]]++;

            while (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};