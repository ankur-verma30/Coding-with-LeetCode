class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int>freqArray(3,0);

        int minCount = n;

        for (char ch : s)
            freqArray[ch - 'a']++;
        for (int freq : freqArray)
            if (freq < k)
                return -1;

        int start = 0, minutes = n;

        for (int end = 0; end < n; end++) {
            freqArray[s[end] - 'a'] -= 1;
            while (start <= end &&
                   (freqArray[0] < k || freqArray[1] < k || freqArray[2] < k)) {
                freqArray[s[start++] - 'a'] += 1;
            }
            minutes = min(minutes, n - (end - start + 1));
        }
        return minutes;
    }
};