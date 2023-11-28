class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n==1)
        return true;

        int last_bit=(n&1);
        n=n>>1;

        while(n){
            int res=(n&1);
            if(res^last_bit)
                last_bit=res;
                else{
                    return false;
                    break;
                }
                n=n>>1;
        }
        return true;
    }
};