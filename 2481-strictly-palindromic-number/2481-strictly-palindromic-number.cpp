class Solution {
public:
    bool isPalindrome(string str) {
        int n = str.length();
        for (int i = 0; i < n; i++) {
            if (str[i] != str[n - i - 1])
                return false;
        }
        return true;
    }

    string ConversionToBase(int n, int base) {
        string str;
        while (true) {
            if (n % base == 0)
                str += '0';
            else
                str += to_string(n % base);

            n = n / base;
            if (n < base) {
                str += to_string(n);
                break;
            }
        }
        return str;
    }

    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++){
            string str=ConversionToBase(n,i);
            if(!isPalindrome(str)) return false;
    }

    return true;
    }
}
;