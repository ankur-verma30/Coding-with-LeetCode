class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int totalPaper = 0, totalGlass = 0, totalMetal = 0;
        int lastP = -1, lastG = -1, lastM = -1;

        for (int i = 0; i < n; i++) {
            int paperCount = count(garbage[i].begin(), garbage[i].end(), 'P');
            int glassCount = count(garbage[i].begin(), garbage[i].end(), 'G');
            int metalCount = count(garbage[i].begin(), garbage[i].end(), 'M');

            totalPaper+=paperCount, totalGlass+=glassCount, totalMetal+=metalCount;
            if (paperCount) lastP = i;
            if (glassCount) lastG = i;
            if (metalCount) lastM = i;
        }

        int travelTime = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i < lastP) travelTime += travel[i];
            if (i < lastG) travelTime += travel[i];
            if (i < lastM) travelTime += travel[i];
        }

        return totalPaper + totalGlass + totalMetal + travelTime;
    }
};
