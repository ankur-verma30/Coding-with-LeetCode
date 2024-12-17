class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        string res = "";
        int index = 25;
        while (index >= 0) {
            if (freq[index] == 0) {
                index--;
                continue;
            }

            int used = min(freq[index], repeatLimit);
            for (int k = 0; k < used; k++)
                res += (char)('a' + index);
            freq[index] -= used;

            if (freq[index] > 0) {
                int prevIndex = index - 1;
                while (prevIndex >= 0 && freq[prevIndex] == 0)
                    prevIndex--;
                if (prevIndex < 0)
                    break;

                res += (char)('a' + prevIndex);
                freq[prevIndex]--;
            }
        }

        return res;
    }
};