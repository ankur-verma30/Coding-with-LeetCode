class Solution {
public:
    int numberOfChild(int n, int k) {
        int quo=k/(n-1);
        int rem=k%(n-1);

        if(quo%2==0){
            return rem;
        }
        else return n-1-rem;
    }
};