class Solution {
public:
    int productOfDigit(int n) {
        int pro = 1;
        while (n > 0) {
            int rem = n % 10;
            pro *= rem;
            n /= 10;
        }

        return pro;
    }
    int smallestNumber(int n, int t) {
        int ans = 0;
        while (true) {
            if ((productOfDigit(n)%t) == 0) {
                ans = n;
                break;
            }
            n++;
        }

        return ans;
    }
};