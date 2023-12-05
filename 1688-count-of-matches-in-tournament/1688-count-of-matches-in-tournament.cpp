class Solution {
public:
    int numberOfMatches(int n) {
        int matches=0,advanced=0;

        while(n>1){
            if(n%2!=0){
                matches+=(n-1)/2;
                advanced=((n-1)/2)+1;
                n=advanced;
            }
            else{
                matches+=n/2;
                advanced=n/2;
                n=advanced;
            }
        }
        return matches;
    }
};