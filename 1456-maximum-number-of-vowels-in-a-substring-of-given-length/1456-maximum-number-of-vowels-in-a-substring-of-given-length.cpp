class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0,left=0,right=0;
        int len=s.length();
        int maxCount=0;

        while(right<len){
            if(s[right]=='a' || s[right]=='e' ||s[right]=='i' 
            || s[right]=='o'|| s[right]=='u') count++;

            if(right-left+1>k){
                if(s[left]=='a' || s[left]=='e' ||s[left]=='i' 
            || s[left]=='o'|| s[left]=='u') count--;
            left++;
            }

            if(right-left+1==k) maxCount=max(maxCount,count);
            right++;
        }

        return maxCount;
    }
};