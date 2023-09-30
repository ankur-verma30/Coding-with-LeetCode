class Solution {
public:
    bool isPowerOfThree(int n) {
       if(n==0)
    return false;
    if((n==1)||((n%3==0)&&isPowerOfThree(n/3)))
    return true;
    return 0; 
    }
};