class Solution {
public:
    int GCD(int num1, int num2) {
        return __gcd(num1, num2);
    }

    int LCM(int a, int b) {
        return (a * b) / GCD(a, b);
    }

    string fractionAddition(string s) {
        vector<int> numerators, denominators;
        int n = s.length();
        int i = 0;

        while (i < n) {
            int sign = 1;
            if (s[i] == '-' || s[i] == '+') {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }

            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            numerators.push_back(sign * num);

            i++;


            int denom = 0;
            while (i < n && isdigit(s[i])) {
                denom = denom * 10 + (s[i] - '0');
                i++;
            }
            denominators.push_back(denom);
        }

        int lcm = denominators[0];
        for (int i = 1; i < denominators.size(); i++) {
            lcm = LCM(lcm, denominators[i]);
        }

        int sum = 0;
        for (int i = 0; i < numerators.size(); i++) {
            sum += numerators[i] * (lcm / denominators[i]);
        }

        int common = GCD(abs(sum), lcm);
        int numerator = sum / common;
        int denominator = lcm / common;

        return to_string(numerator) + '/' + to_string(denominator);
    }
};
