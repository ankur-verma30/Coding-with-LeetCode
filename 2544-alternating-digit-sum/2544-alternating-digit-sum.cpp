class Solution {
public:
    int alternateDigitSum(int n) {
        //reverse the number then apply the logic
         int rev = 0;
        
        while(n)
        {
            rev = rev * 10 + n % 10;
            
            n = n / 10;
        }  
        int sum = 0;
        
        int pos = 1;
        
        while(rev)
        {
            if(pos % 2 == 1)
            {
                sum += rev % 10;
            }
            else
            {
                sum -= rev % 10;
            }
            
            pos++;
            
            rev = rev / 10;
        }
        
        return sum;
    }
};