class Solution {
public:
    void helper(int index, vector<vector<int>>& res, vector<int>& candi,
                vector<int> temp, int sum, int target) {
        if (sum == target) {
            res.push_back(temp);
            return;
        }
        if (sum > target || index >= candi.size())
            return;

        for (int i = index; i < candi.size(); i++) {
            if (i > index && candi[i] == candi[i - 1])
                continue;

            temp.push_back(candi[i]);
            helper(i + 1, res, candi, temp, sum + candi[i], target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candi.begin(), candi.end());

        helper(0, res, candi, temp, 0, target);

        return res;
    }
};