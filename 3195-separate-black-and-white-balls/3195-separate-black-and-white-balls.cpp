class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();

        int whiteBall = count(s.begin(), s.end(), '0');
        int blackBall = count(s.begin(), s.end(), '1');

        if (whiteBall == n || blackBall == n)
            return 0;

        int sum = 0,i=0;
        long long ans=0;
      
        while (whiteBall && i < n) {
            if (s[i] == '1')
                sum++;
            if (s[i] == '0') {
                whiteBall--;
                ans+=sum;
            }
            i++;
        }
        return ans;
    }
};