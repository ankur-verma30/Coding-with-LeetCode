class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[255];
        int left=0,right=0,maxLength=0,diff=0;
        
        for(int i=0;i<255;i++) hash[i]=-1;

        int len=s.length();

        while(right<len){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left) left=hash[s[right]]+1;
            }
            diff=right-left+1;
            maxLength=max(maxLength,diff);
            hash[s[right]]=right;
            right++;
        }

        return maxLength;
    }
};