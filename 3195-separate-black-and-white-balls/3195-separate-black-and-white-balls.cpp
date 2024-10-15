class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();

        int whiteBall = count(s.begin(), s.end(), '0');
        int blackBall = count(s.begin(), s.end(), '1');

        if (whiteBall == n || blackBall == n)
            return 0;

        int sum = 0;
        vector<int> res;
        int i = 0;
        while (whiteBall && i < n) {
            if (s[i] == '1')
                sum++;
            if (s[i] == '0') {
                whiteBall--;
                res.push_back(sum);
            }
            i++;
        }

        long long ans = 0;
        for (auto x : res)
            ans += x;

        return ans;
    }
};