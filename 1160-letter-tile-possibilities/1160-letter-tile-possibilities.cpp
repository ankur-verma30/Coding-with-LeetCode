class Solution {
public:
    int solve(vector<int>&frequency){
        int count=0;
        for(int i=0;i<26;i++){
            if(frequency[i]==0) continue;
            count++;
            frequency[i]--;
            count+=solve(frequency);
            frequency[i]++;
        }
        return count;
    }
    int numTilePossibilities(string tiles) {
        int len=tiles.length();
        vector<int>frequency(26,0);

        for(int i=0;i<len;i++){
            frequency[tiles[i]-'A']++;
        }

        int count=solve(frequency);
        return count;
    }
};