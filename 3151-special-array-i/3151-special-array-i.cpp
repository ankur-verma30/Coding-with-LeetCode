class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int len = nums.size();
        int flag = true;

        for (int i = 1; i < len; i++) {
            flag &= ((nums[i] % 2) != (nums[i - 1] % 2));
        }
        return flag;
    }
};