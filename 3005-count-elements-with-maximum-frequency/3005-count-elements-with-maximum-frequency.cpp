class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

       sort(nums.begin(), nums.end());

    int count = 1, maxCount = 1;
    int maxFrequency = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                maxFrequency = 1;
            } else if (count == maxCount) {
                maxFrequency++;
            }
            count = 1;
        }
    }

    if (count > maxCount) {
        maxCount = count;
        maxFrequency = 1;
    } else if (count == maxCount) {
        maxFrequency++;
    }

    return maxFrequency*maxCount;
    }
};