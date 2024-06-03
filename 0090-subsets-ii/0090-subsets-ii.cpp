class Solution {
public:
    void solve(int index,vector<int>&nums,vector<int>&ds,vector<vector<int>>&res){
            res.push_back(ds);

        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1,nums,ds,res);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>res;
        solve(0,nums,ds,res);

        return res;
    }
};