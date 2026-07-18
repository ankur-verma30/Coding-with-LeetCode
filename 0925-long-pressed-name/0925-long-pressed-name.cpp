class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int n1 = name.length(), n2 = typed.length();

        while (i < n1 && j < n2) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }
            else {
                return false;
            }
        }

        // Remaining characters in typed must all be repeats
        while (j < n2) {
            if (typed[j] != typed[j - 1])
                return false;
            j++;
        }

        return i == n1 && j == n2;
    }
};