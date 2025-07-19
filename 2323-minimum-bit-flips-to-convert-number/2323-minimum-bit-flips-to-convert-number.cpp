class Solution {
public:
    int minBitFlips(int start, int goal) {
         int newNum=start^goal;
       return __builtin_popcount(newNum);
    }
};