class Solution {
public:
    string Conversion(long long n, int base) {
        int rem = 0;
        string ans = "";

        while (n >= base) {
            int rem = n % base;
            if (rem < 10)
                ans += (rem + '0');
            else 
                ans += ('A' + (rem - 10));
            n = n / base;
        }
        
        if (n < 10)
            ans += (n + '0');
        else
            ans += ('A' + (n- 10));
        reverse(ans.begin(),ans.end());
        return ans;

    }
    string concatHex36(int n) {
        long long SquareN = n * n;
        long long cubeN = n * n * n;
        string ans1 = Conversion(SquareN, 16);
        string ans2 = Conversion(cubeN, 36);

        return ans1 + ans2;
    }
};