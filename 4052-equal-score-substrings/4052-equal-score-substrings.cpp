class Solution {
public:
    bool scoreBalance(string s) {
       int totalSum=0,n=s.length();

       for(int i=0;i<n;i++){
        totalSum+=(s[i]-'a')+1;
       }

        if(totalSum%2) return false;

        int currSum=0;
       for(int i=0;i<n;i++){
        currSum+=(s[i]-'a')+1;
        if(currSum==totalSum/2) return true;
       }

       return false;
    }
};