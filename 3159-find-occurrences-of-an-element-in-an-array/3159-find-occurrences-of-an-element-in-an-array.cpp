class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        vector<int> Indices;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                Indices.push_back(i);
            }
        }

        vector<int> ans(queries.size(), -1);

        for (int i = 0; i < queries.size(); i++) {
            int occurrence = queries[i];
            if (occurrence <= Indices.size()) {
                ans[i] = Indices[occurrence - 1];
            } else {
                ans[i] = -1;
            }
        }

        return ans;
    }
};