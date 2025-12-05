class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;

        int n = fruits.size(), left = 0, maxFruit = 0;

        for (int right = 0; right < n; right++) {
            freq[fruits[right]]++;

            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0)
                    freq.erase(fruits[left]);
                left++;
            }

            maxFruit = max(maxFruit, right - left + 1);
        }

        return maxFruit;
    }
};