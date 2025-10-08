class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int totalPaper = 0, totalGlass = 0, totalMetal = 0;
        int lastP = -1, lastG = -1, lastM = -1;

        // First, count all garbage and mark last seen index
        for (int i = 0; i < n; i++) {
            totalPaper += count(garbage[i].begin(), garbage[i].end(), 'P');
            totalGlass += count(garbage[i].begin(), garbage[i].end(), 'G');
            totalMetal += count(garbage[i].begin(), garbage[i].end(), 'M');

            if (garbage[i].find('P') != string::npos) lastP = i;
            if (garbage[i].find('G') != string::npos) lastG = i;
            if (garbage[i].find('M') != string::npos) lastM = i;
        }

        // Then add travel times properly
        int travelTime = 0;
        for (int i = 0; i < n - 1; i++) {
            // travel[i] is time to go from i → i+1
            if (i < lastP) travelTime += travel[i];
            if (i < lastG) travelTime += travel[i];
            if (i < lastM) travelTime += travel[i];
        }

        return totalPaper + totalGlass + totalMetal + travelTime;
    }
};
