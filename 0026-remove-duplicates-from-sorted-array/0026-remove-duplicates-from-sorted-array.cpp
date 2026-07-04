class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        vector<int> temp;
        temp.push_back(nums[0]);

        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1])
                temp.push_back(nums[i]);
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        return (int)temp.size();
    }
};