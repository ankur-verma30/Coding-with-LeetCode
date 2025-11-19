class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size(),maxLen=0;
        vector<int>peakIndecies;

        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) peakIndecies.push_back(i);
        }

        if(peakIndecies.empty()) return 0;
        maxLen=3;

        for(const auto index:peakIndecies){
            //go to left;
            int currLeft=arr[index];
            int leftLen=0,rightLen=0;
            for(int i=index-1;i>=0;i--){
                if(arr[i]<currLeft) {
                    currLeft=arr[i];
                    leftLen=index-i;
                }
                else break;
                
            }
            //go to right
            int currRight=arr[index];
            for(int i=index+1;i<n;i++){
                if(arr[i]<currRight) {
                    currRight=arr[i];
                    rightLen=i-index;
                }
                else break;
                
            }
            maxLen=max(maxLen,leftLen+rightLen+1);
        }

        return maxLen;
    }
};