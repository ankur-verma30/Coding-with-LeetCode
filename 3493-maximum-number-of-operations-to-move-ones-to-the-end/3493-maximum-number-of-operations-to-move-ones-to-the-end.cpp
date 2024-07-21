class Solution {
public:
    int maxOperations(string s) {
        reverse(s.begin(), s.end());

        int n = s.length(), start = n;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                start = i;
                break;
            }
        }

        int ans = 0, j = -1, impact = 1;
        for (int i = start; i < n; i++) {
            if (s[i] == '0')
                continue;
            int count = 0;
            for (j = i; j < n; j++) {
                if (s[j] == '0')
                    break;
                count++;
            }
            ans += (count * impact);
            impact++;
            i = j - 1;
        }

        return ans;
    }
};