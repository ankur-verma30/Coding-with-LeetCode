class Solution {
public:
    void solve(int index, vector<int>& nums, int n, int& count,int curr,
               int maxOr) {
        if (index == n) {
            if (curr == maxOr)
                count++;
            return;
        }
        solve(index + 1, nums, n, count,curr | nums[index],maxOr);
        solve(index + 1, nums, n, count,curr, maxOr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, n = nums.size();
        for (int i = 0; i < n; i++)  maxOr = maxOr | nums[i];
        
        int count = 0;
        solve(0, nums, n, count,0, maxOr);
        return count;
    }
};