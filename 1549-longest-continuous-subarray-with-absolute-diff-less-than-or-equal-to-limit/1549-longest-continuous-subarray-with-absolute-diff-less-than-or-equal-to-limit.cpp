class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       deque<int> maxi;
    deque<int> mini;
    int left = 0;
    int maxlen = 0;

    for (int right = 0; right < nums.size(); ++right) {
        while (!maxi.empty() && nums[right] > maxi.back()) {
            maxi.pop_back();
        }
        maxi.push_back(nums[right]);

        while (!mini.empty() && nums[right] < mini.back()) {
            mini.pop_back();
        }
        mini.push_back(nums[right]);

        while (!maxi.empty() && !mini.empty() && (maxi.front() - mini.front() > limit)) {
            if (nums[left] == maxi.front()) {
                maxi.pop_front();
            }
            if (nums[left] == mini.front()) {
                mini.pop_front();
            }
            ++left;
        }

        maxlen = max(maxlen, right - left + 1);
    }

    return maxlen;
    }
};