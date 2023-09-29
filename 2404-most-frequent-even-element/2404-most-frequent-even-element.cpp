class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
   unordered_map<int, int> mp;
    vector<int> v;
    int mx = 0;
    int mn = INT_MAX;

    for (auto x : nums)
        mp[x]++;

    for (auto x : mp) {
        if (x.first % 2 == 0)
            mx = std::max(mx, x.second);
    }

    if (mx == 0)
        return -1;

    for (auto x : mp) {
        if (mx == x.second && x.first % 2 == 0)
          mn=min(x.first,mn);
    }
   return mn;
}

};