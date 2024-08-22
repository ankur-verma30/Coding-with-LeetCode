class Solution {
public:
    int findComplement(int num) {
        int count = 0;
        int n = num;
        while (n > 0) {
            count++;
            n = n >> 1;
        }
        
        for (int i = 0; i < count; i++)
            num = num ^ (1 << i);

        return num;
    }
};