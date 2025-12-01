class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.length(),firstBlackIndex=0;
        long long blackCount=0,swapCount=0;

        while(firstBlackIndex<n && s[firstBlackIndex]!='1') firstBlackIndex++;

        for(int i=firstBlackIndex;i<n;i++){
            if(s[i]=='1') blackCount++;
            if(s[i]=='0') swapCount+=blackCount;
         
        }

        return swapCount;
    }
};