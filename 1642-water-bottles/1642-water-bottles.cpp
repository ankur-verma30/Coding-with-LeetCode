class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0, count = 0, rem = 0;
        sum += numBottles;

        while (numBottles >= numExchange) {

            count = numBottles / numExchange;
            sum += count;
            rem = numBottles % numExchange;
            numBottles = rem + count;
        }
        return sum;
    }
};