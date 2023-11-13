class Solution {
public:
    string sortVowels(string s) {
         string vowels;
        int i = 0;

        // Collect vowels and update the string with them
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels += c;
            }
        }

        // Sort the collected vowels
        sort(vowels.begin(), vowels.end());

        // Replace original string with sorted vowels
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                s[i] = vowels[j++];
            }
        }
        return s;
    }
};