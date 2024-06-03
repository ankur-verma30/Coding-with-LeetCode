class Solution {
public:
    void solve(int index, vector<int>& candidates, vector<vector<int>>& res,
               vector<int> ds, int target) {
        if (index == (int)candidates.size()) {
            if (target == 0) {
                res.push_back(ds);
            }
            return;
        }
        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
        
        solve(index, candidates, res, ds, target - candidates[index]);
        ds.pop_back();
        }
        solve(index + 1, candidates, res, ds, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        int sum = 0;
        solve(0, candidates, res, ds, target);
        return res;
    }
};