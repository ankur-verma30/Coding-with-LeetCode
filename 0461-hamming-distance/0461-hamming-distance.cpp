class Solution {
public:
    int hammingDistance(int x, int y) {
      int xor_result = x ^ y;
        int distance = 0;

        // Count the number of set bits in the XOR result
        while (xor_result) {
            distance += xor_result & 1;
            xor_result >>= 1;
        }

        return distance;
    
    }
};