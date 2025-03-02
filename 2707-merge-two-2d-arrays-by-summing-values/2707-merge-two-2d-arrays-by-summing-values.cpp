class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int, int> mp;

        for (const auto num : nums1)
            mp[num[0]] = num[1];

        for (const auto num : nums2) {
            int id = num[0];
            if (mp.find(id) != mp.end()) {
                res.push_back({id, mp[id] + num[1]});
                mp.erase(id);
            } else
                res.push_back({id, num[1]});
        }

        for (const auto& [id, num] : mp)
            res.push_back({id, num});

        sort(res.begin(), res.end());

        return res;
    }
};