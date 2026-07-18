class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);

        int length = word.length();

        for (int i = 0; i < length; i++) {
            freq[word[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            int f = 0;
            freq[i]--;

            bool isSame = true;

            for (int j = 0; j < 26; j++) {
                if (freq[j] == 0)
                    continue;
                if (f == 0)
                    f = freq[j];
                else if (freq[j] != f) {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
                return true;
            freq[i]++;
        }

        return false;
    }
};