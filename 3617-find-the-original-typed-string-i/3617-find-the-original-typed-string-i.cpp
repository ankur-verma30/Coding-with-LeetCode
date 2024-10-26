class Solution {
public:
    int possibleStringCount(string word) {
        int len = word.length();
        int count = 1;

        for (int i = 1; i < len; i++) {
            if (word[i] == word[i - 1])
                count++;
            else
                continue;
        }

        return count;
    }
};