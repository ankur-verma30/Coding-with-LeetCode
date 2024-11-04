class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;
        int n = word.length();

        while (i < n) {
            int count = 0;
            char ch = word[i];
            while (i < n && word[i] == ch) {
                count++;
                i++;
                if (count == 9)
                    break;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};