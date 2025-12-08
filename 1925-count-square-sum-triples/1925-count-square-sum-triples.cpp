class Solution {
public:
  int sqrtOfN(long long n)
    {
        if (n < 2) {
            return n;
        }
        int low = 1, high = n;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (mid * mid == n) {
                return mid;
            }
            else if (mid * mid < n) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int countTriples(int n) {
        int squareOfN = n * n;

        set<pair<int,int>>st;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if(st.count({i,j})) continue;
                if(st.count({j,i})) continue;
                int totalSquare = i * i + j * j;
                int m=sqrtOfN(totalSquare);
                if (totalSquare <= squareOfN && m!=-1 && m<=n){
                    st.insert({i,j});
                    st.insert({j,i});
                }
            }
        }

        return st.size();
    }
};