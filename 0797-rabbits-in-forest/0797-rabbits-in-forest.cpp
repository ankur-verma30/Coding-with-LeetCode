class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mpp;

        for (const auto ans : answers) mpp[ans]++;

        int totalRabbits = 0;

        for (const auto &[answer,candidates] : mpp){
            int groupSize=answer+1;
            int groups=ceil((double)candidates/groupSize);

            totalRabbits+=groups*groupSize;

        }
        return totalRabbits;
    }
};