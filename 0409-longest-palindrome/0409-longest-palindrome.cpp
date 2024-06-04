class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;
        int odd=0;

        for(char ch:s){
            mpp[ch]++;
            if(mpp[ch]%2!=0){
                odd+=1;
            }
            else odd--;
        }

        return min(s.length(),s.length()-odd+1);
    }
};