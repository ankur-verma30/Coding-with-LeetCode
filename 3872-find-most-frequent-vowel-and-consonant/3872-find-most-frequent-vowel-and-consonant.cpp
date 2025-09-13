class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};

        int vowelFreq = 0, consonantFreq = 0;
        for (char &character:s) {
            freq[character]++;
            if (st.count(character))
                vowelFreq = max(vowelFreq, freq[character]);
            else
                consonantFreq = max(consonantFreq, freq[character]);
        }

        return vowelFreq + consonantFreq;
    }
};