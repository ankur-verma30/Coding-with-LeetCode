class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        if(x==2)
            return 1;
        for( long int i=1;i<x;i++)
        {
        if(x<i*i)
        {
            return i-1;
            break;
        }
        }
        return 0;
    }
};