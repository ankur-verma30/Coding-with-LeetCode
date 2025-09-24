class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator, d = denominator;
        if (n == d)
            return "1";
        if (d == 1)
            return to_string(n);
        if (n == 0)
            return "0";

        bool isNegative=false;
        if(numerator<0 ^ denominator<0) isNegative=true;

        n=llabs(n);
        d=llabs(d);    

        string ans = "";
        ans += to_string(n / d);
        long long rem = n % d;

        if (rem == 0) return (isNegative) ? "-"+ans : ans;

        ans.push_back('.');
        int count = 0;
        unordered_map<long long, int> mpp;

        while (rem != 0) {
            if (mpp.count(rem)) {
                ans.insert(mpp[rem], "(");
                ans += ")";
                break;
            }
            mpp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }
        return (isNegative) ? "-"+ans : ans;
    }
};