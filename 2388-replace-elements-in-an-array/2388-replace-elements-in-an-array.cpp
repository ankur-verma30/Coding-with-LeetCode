class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
            mpp[nums[i]] = i;

        for (int i = 0; i < op.size(); i++) {
            nums[mpp[op[i][0]]] = op[i][1];
            mpp[op[i][1]] = mpp[op[i][0]];
        }
        return nums;
    }
};