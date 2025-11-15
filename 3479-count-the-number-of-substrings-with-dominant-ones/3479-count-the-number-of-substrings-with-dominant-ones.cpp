class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> prefixOne(n, 0);

        prefixOne[0] = ((s[0] == '1') ? 1 : 0);

        for (int i = 1; i < n; i++) {
            int value = (s[i] == '1') ? 1 : 0;
            prefixOne[i] = prefixOne[i - 1] + value;
        }

        //[i,j] =prefixOne[j]-prefixOne[i-1]; gives count of ones
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n;j++) {
                int ones = prefixOne[j] - (i - 1 >= 0 ? prefixOne[i - 1] : 0);
                int zeroes = (j - i + 1) - ones;
                if ((zeroes * zeroes) > ones) {
                    int skipIndices = (zeroes * zeroes) - ones;
                    j += skipIndices - 1;
                } else if ((zeroes * zeroes) == ones)
                    ans++;
                else {
                    ans++;
                    int extraIndices = sqrt(ones) - zeroes;
                    int nextIndex = j + extraIndices;
                    if (nextIndex >= n){
                        ans += (n - j - 1);
                        break;
                    }
                    else ans+=extraIndices;
                    j=nextIndex;
                }
            }
        }
        return ans;
    }
};