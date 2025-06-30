class Solution {
public:
    int solve(vector<int>& nums, int target) {
        if (target < 1)
            return 0;

        unordered_map<int, int> mpp;
        int n = nums.size(), left = 0, count = 0;

        for (int right = 0; right < n; right++) {
            mpp[nums[right]]++;

            while (mpp.size() > target) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;

        for (const auto& it : nums)
            st.insert(it);

        int distinct = st.size();

        return solve(nums, distinct) - solve(nums, distinct - 1);
    }
};