class Solution {
public:
    int maxProduct(int n) {
        if(n<10) return n;
        vector<int> digits;

        while(n>0){
            int rem=n%10;
            digits.push_back(rem);
            n=n/10;
        }

        sort(digits.begin(),digits.end());

        int size=digits.size();

        return digits[size-1]*digits[size-2];
    }
};