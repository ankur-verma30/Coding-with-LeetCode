class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        unordered_set<int> st;

        for (long long i = 1; i * i <= target; i++) {
            if (target % i == 0) {
                st.insert(i);
                st.insert(target / i);
            }
        }

        for (const auto it : nums) {
            if (!st.count(it))
                return false;
        }

        return true;
    }
};