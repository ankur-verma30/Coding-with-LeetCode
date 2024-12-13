class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int first = 0, second = 0;

        vector<int> arr;
        for (int second = 1; second < n; second += 2) {
            arr.push_back(nums[second]);
            arr.push_back(nums[first]);
            first += 2;
        }

        return arr;
    }
};