class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long long> squares;
        squares.push_back(0);
        
        // Use long long for i to prevent overflow
        for (long long i = 1; i * i <= c; i++) {
            squares.push_back(i * i);
        }

        // Check if c itself is a perfect square
        if(binary_search(squares.begin(), squares.end(), (long long)c)) return true;

        // Use long long for i in the loop
        for (long long i = 1; i * i <= c; i++) {
            long long rem = (long long)c - (i * i);
            if (rem < 0)
                return false;
            if (binary_search(squares.begin(), squares.end(), rem))
                return true;
        }

        return false;
    
    }
};