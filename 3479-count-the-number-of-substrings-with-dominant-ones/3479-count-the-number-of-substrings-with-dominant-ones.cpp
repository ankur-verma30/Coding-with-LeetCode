class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int res = 0;

        vector<int> prefix(n, 0);
        prefix[0] = (s[0] == '1') ? 1 : 0;

        // prefix sum of ones
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + ((s[i] == '1') ? 1 : 0);
        }

        for (int i = 0; i < n; i++) {
            int zero = 0, one = 0;
            for (int j = i; j < n; j++) {
                one = prefix[j] - (i == 0 ? 0 : prefix[i - 1]);
                zero = j - i + 1 - one;

                if (zero * zero > one)
                    j += (zero * zero - one - 1);

                if (zero * zero <= one) {
                    res++;
                    int root = static_cast<int>(sqrt(one));
                    if (root > zero) {
                        res += (j + (root - zero)) >= n ? (n - j - 1)
                                                        : (root - zero);
                        j += (root - zero);
                    }
                }
            }
        }
        return res;
    }
};