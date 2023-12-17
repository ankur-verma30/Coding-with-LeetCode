class Solution {
public:
    bool judgeSquareSum(int c) {
        int low=0;
       long long int high=pow(c,0.5);

        if(c==1) return true;

        while(low<=high){
            if(high==pow(c,0.5))
            return true;
            if(high>pow(c,0.5))
            high--;
            else{
                if((high*high+low*low)==c)
                return true;
                else if((high*high+low*low)<c)
                low++;
                else 
                high--;
            }
        }
        return false;
    }
};