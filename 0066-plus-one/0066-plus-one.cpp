class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        reverse(digits.begin(),digits.end());

        for(int i=0;i<digits.size();i++){
            int sum=digits[i]+carry;
            if(sum>=10){
                digits[i]=sum%10;
                carry=sum/10;
            }
            else{
                 digits[i]=sum;
                 carry=0;
                 break;
            }
            
            
        }
        if(carry)
        digits.push_back(1);

        reverse(digits.begin(),digits.end());

        return digits;
    }
};