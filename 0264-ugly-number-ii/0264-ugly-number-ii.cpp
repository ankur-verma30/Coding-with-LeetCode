class Solution {
public:
    int nthUglyNumber(int n) {
         vector<long long> num(n,1);

        int i2 = 0,i3 = 0,i5 = 0;
        long long nextNum = 0;

        for(int i = 1;i < n;i++)
        {
            nextNum = min(num[i2]*2,min(num[i3]*3,num[i5]*5));
            num[i] = nextNum;
            if(nextNum == num[i2]*2)
            i2++;
            if(nextNum == num[i3]*3)
            i3++;
            if(nextNum == num[i5]*5)
            i5++;
        }
        return num[n-1];
    }
};