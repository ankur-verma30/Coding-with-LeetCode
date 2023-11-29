class Solution {
public:
    vector<int> evenOddBit(int n) {
        int Even=0,Odd=0,i=0;

        while(n){
            if(n&1){
                if(i%2==0)  Even++;
                else
                Odd++;
            }
            i++;
            n=n>>1;
        }
        return {Even,Odd};
    }
};