class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>freq(501,0);

        for(const auto it:arr) freq[it]++;

        int maxValue=-1;

        for(int i=1;i<501;i++){
            if(freq[i]==i) maxValue=max(maxValue,i);
        }

        return maxValue;
    }
};