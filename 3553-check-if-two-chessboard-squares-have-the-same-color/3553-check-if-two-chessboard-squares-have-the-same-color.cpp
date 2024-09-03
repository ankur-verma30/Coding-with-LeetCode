class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int val1 = c1[0] - 'a' + 1;
        int val2 = c2[0] - 'a' + 1;

        int pos1 = c1[1] - '0';
        int pos2 = c2[1] - '0';

        if ((val1 + val2 + pos1 + pos2) % 2 == 0)
            return true;

        return false;
    }
};