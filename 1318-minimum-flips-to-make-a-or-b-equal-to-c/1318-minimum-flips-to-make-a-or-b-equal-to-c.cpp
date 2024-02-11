class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;

        while (a || b||c) {
            if (c & 1) {
                if ((a & 1) == 0 && (b & 1) == 0)
                    count++;
            }
            if ((c & 1) == 0) {
                if (a & 1)
                    count++;
                if (b & 1)
                    count++;
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return count;
    }
};