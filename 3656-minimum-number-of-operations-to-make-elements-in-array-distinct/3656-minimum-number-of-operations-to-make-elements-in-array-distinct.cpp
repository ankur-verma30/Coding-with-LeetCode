class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int ans = 0;

        while (nums.size() > 0) {
            unordered_set<int> seen;
            bool isDistinct = true;

            for (int num : nums) {
                if (seen.count(num)) {
                    isDistinct = false;
                    break;
                }
                seen.insert(num);
            }

            if (isDistinct) return ans;
            
            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            ans++;
        }

        return ans;
    }
};