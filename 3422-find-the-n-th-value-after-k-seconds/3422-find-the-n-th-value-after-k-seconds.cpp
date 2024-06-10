class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9 + 7;
        vector<int> ans(n, 1);

        for (int i = 1; i <= k; i++) {
            long long int temp = ans[0]%mod;
            for (int j = 1; j < n; j++) {
                temp += ans[j]%mod;
                ans[j] = temp%mod;
            }
        }

        return ans[n - 1]%mod;
    }
};