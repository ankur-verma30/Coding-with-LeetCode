class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        int n = nums1.size();
        vector<vector<int>> elements(n);

        for (int i = 0; i < n; i++)
            elements[i] = {nums1[i], nums2[i], i};

        sort(elements.begin(), elements.end());

        vector<long long> result(n);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int num = elements[i][0];
            int weight = elements[i][1];
            long long index = elements[i][2];

            if (i > 0 && num == elements[i - 1][0])
                result[index] = result[elements[i - 1][2]];
            else
                result[index] = sum;

            pq.push(weight);
            sum += weight;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return result;
    }
};