class Solution {
public:
    int maxUniqueLetters(string s) {
        unordered_set<char> st;
        for (const auto it : s)
            st.insert(it);

        return st.size();
    }
    int longestSubstring(string s, int k) {
        int freq[26];
        int maxUnique = maxUniqueLetters(s);
        int maxLen = 0;

        for (int currUniqueLetters = 1; currUniqueLetters <= maxUnique;
             currUniqueLetters++) {
            memset(freq, 0, sizeof(freq));
            int left = 0, right = 0, index = 0, unique = 0, countAtLeastK = 0;

            while (right < s.size()) {
                if (unique <= currUniqueLetters) {
                    index = s[right] - 'a';
                    if (freq[index] == 0) unique++;
                    freq[index]++;
                    if (freq[index] == k) countAtLeastK++;
                    right++;
                } else {
                    index = s[left] - 'a';
                    if (freq[index] == k)
                        countAtLeastK--;
                    freq[index]--;
                    if (freq[index] == 0)
                        unique--;
                    left++;
                }
                if (unique == currUniqueLetters && unique == countAtLeastK)
                    maxLen = max(right - left, maxLen);
            }
        }
        return maxLen;
    }
};