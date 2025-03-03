class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int n1 = firstList.size(), n2 = secondList.size();

        if (n1 == 0 || n2 == 0)
            return {};

        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < n1 && j < n2) {
            auto q1 = firstList[i], q2 = secondList[j];
            int start = max(q1[0], q2[0]);
            int end = min(q1[1], q2[1]);
            if (start <= end)
                ans.push_back({start, end});
            if (q1[1] < q2[1])
                i++;
            else
                j++;
        }

        return ans;
    }
};