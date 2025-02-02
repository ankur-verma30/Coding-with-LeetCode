class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;

        for(const auto ch:s){
            mpp[ch]++;
        }

        int maxOdd=0,minEven=INT_MAX;
        for(const auto &[ele,freq]:mpp){
            if(freq%2){
                maxOdd=max(maxOdd,freq);
            }
            else{
                minEven=min(minEven,freq);
            }
        }

        return (maxOdd-minEven);
    }
};