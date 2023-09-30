class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
       for( long int i=2;i<=num/2;i++)
    if(num==i*i)
        return true;
        else if(num>i*i)
            continue;
        else 
            return false;
        return 0;
    }
    
};