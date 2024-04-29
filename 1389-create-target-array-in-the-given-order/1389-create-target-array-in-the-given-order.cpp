class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int len = nums.size();
        vector<int> target(len);

        for (int i = 0; i < len; i++) {

            if (target[index[i]] != -1) {
                for (int counter = len - 2; counter >= index[i]; counter--) {
                    target[counter + 1] = target[counter];
                }
            }
            target[index[i]] = nums[i];
        }

        return target;
    }
};