class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalCount = 0, fullBottles = 0;
        if (numBottles < numExchange)
            return numBottles;
        if (numBottles == numExchange)
            return numBottles + 1;

        totalCount += numBottles; // 13

        while (numBottles >= numExchange) {
            if (numBottles / numExchange) {
                numBottles = numBottles - numExchange;//7
                fullBottles++;//1
                numExchange++;//4
                while (numBottles > numExchange) {
                    fullBottles++;//2                         // fb=2
                    numBottles  -= numExchange; // nm=7-4=3
                    numExchange++;                         // ne=5
                }
                if (numBottles < numExchange) {
                    numBottles += fullBottles;
                    totalCount += fullBottles;
                    fullBottles = 0;
                }
            }
        }
        return totalCount ;
    }
};