class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
    int n = s.length(), currZeroes = 0, prevZeroes = 0, zeroSegment = 0,
            onesCount = 0;
        int maxOnes = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                currZeroes++;
            else {
                onesCount++;
                maxOnes = max(maxOnes, prevZeroes + currZeroes);
                if (currZeroes != 0) {
                    prevZeroes = currZeroes;
                    zeroSegment++;
                }
                currZeroes = 0;
            }
        }
        if(currZeroes!=0) zeroSegment++;
        maxOnes = max(maxOnes, prevZeroes + currZeroes);

        return onesCount + ((zeroSegment > 1) ? maxOnes : 0);
    }
};