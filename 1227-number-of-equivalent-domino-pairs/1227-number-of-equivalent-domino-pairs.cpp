class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string,int>mpp;

        int count=0;

        for(const auto domino:dominoes){
            int first=domino[0];
            int second=domino[1];
            if(first>second) swap(first,second);
            string str=to_string(first)+' '+to_string(second);
                int freq=mpp[str];
                count+=freq;
                mpp[str]++;
            
        }

        return count;
    }
};