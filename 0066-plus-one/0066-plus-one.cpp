class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1,n=digits.size();

        for(int i=n-1;i>=0;i--){
            digits[i]+=carry;
            if(digits[i]>=10) {
                digits[i]=0;
                carry=1;
            }
            else {
                carry=0;
                break;
            }
        }
        if(carry) digits.insert(digits.begin(),1);
        return digits;
    }
};