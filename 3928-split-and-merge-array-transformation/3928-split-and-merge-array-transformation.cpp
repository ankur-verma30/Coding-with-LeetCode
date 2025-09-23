class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        string start;

        for (int i = 0; i < n; i++)
            start += to_string(i);

        unordered_map<string, int> distance;
        distance[start] = 0;

        queue<string> q;
        q.push(start);

        int ans = 5;
        while (!q.empty()) {
            auto original = q.front();
            q.pop();

            bool match = true;
            for (int i = 0; i < n; i++) {
                if (nums1[original[i] - '0'] != nums2[i]) {
                    match = false;
                    break;
                }
            }
                if (match)
                    ans = min(ans, distance[original]);
                for (int i = 0; i < n; i++) {
                    for (int j = i; j < n; j++) {
                        string remainingString =
                            original.substr(0, i) +
                            original.substr(j + 1, n - j - 1);
                        string subarray = original.substr(i, j - i + 1);
                        int possiblePosForInsertion =
                            remainingString.size();

                        for (int k = 0; k <= possiblePosForInsertion;
                             k++) {
                            string reInsertedString = remainingString.substr(0, k) +
                                                      subarray +
                                                      remainingString.substr(k, n - k);
                            if (!distance.count(reInsertedString)) {
                                distance[reInsertedString] =
                                    distance[original] + 1;
                                q.push(reInsertedString);
                            }
                        }
                }
            }
        }
        return ans;
    }
};