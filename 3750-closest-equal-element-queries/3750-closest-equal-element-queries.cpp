class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int query : queries) {
            int val = nums[query];
            if (positions[val].size() < 2) {
                ans.push_back(-1);
                continue;
            }

            vector<int>& idxList = positions[val];
            int pos = lower_bound(idxList.begin(), idxList.end(), query) - 
            idxList.begin();

            int leftIndex = (pos - 1 + idxList.size()) % idxList.size();
            int rightIndex = (pos + 1) % idxList.size();

            int leftCandidate = idxList[leftIndex];
            int rightCandidate = idxList[rightIndex];

            int distLeft = abs(query - leftCandidate);
            distLeft = min(distLeft, n - distLeft);

            int distRight = abs(query - rightCandidate);
            distRight = min(distRight, n - distRight);

            ans.push_back(min(distLeft, distRight));
        }

        return ans;

    }
};