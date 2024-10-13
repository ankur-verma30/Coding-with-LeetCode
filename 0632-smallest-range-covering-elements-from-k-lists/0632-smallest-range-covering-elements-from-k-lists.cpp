class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        int k = nums.size();
        int maxi = INT_MIN;

        // initially store all the first values of the list
        for (int i = 0; i < k; i++) {
            int minVal = nums[i][0];
            vector<int> temp = {minVal, i, 0};
            pq.push(temp);
            maxi = max(maxi, minVal);
        }

        vector<int> minRange{0, INT_MAX};
        while (true) {
            vector<int> top = pq.top();
            pq.pop();
            int minElement = top[0], listIndex = top[1], elementIndex = top[2];
            if (maxi - minElement < minRange[1] - minRange[0]) {
                minRange[1] = maxi;
                minRange[0] = minElement;
            }
            if (elementIndex == nums[listIndex].size() - 1)
                break;
            int val = nums[listIndex][elementIndex + 1];
            maxi = max(maxi, val);
            vector<int> dummy = {val, listIndex, elementIndex + 1};
            pq.push(dummy);
        }

        return minRange;
    }
};