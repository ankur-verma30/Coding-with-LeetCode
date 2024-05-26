class Solution {
public:
#define ll long long
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ll count = 0;
        unordered_map<ll, ll> mpp1, mpp2;

        for (int& x : nums1)
            mpp1[x]++;

        for (int& x : nums2)
            mpp2[x]++;

        ll mx = *max_element(nums1.begin(), nums1.end());

        for (auto it : mpp2) {
            ll b = it.first * k;
            ll temp = b;

            while (b <= mx) {
                count += (it.second * mpp1[b]);
                b += temp;
            }
        }

        return count;
    }
};