class Solution {
public:
    bool countFreq(vector<int>& freq, int k) {
        for (int i : freq) {
            if (i >= k)
                return true;
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        int count = 0;
        int i = 0, j = 0;
        vector<int> freq(26, 0);
        int n = s.size();

        while (i < n) {
            freq[s[i] - 'a']++;
            while (j <= i && countFreq(freq, k)) {
                count += (n - i);
                freq[s[j] - 'a']--;
                j++;
            }
            i++;
        }
        return count;
    }
};