class Solution {
public:
    int powerOfNumber(int n, int power) {
        if (n == 1)
            return power;
        if (n % 2 == 0)
            return powerOfNumber(n / 2, power + 1);
        return powerOfNumber(n * 3 + 1, power + 1);
    }
    int getKth(int lo, int hi, int k) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = lo; i <= hi; i++) {
            int power = powerOfNumber(i, 0);
            pq.push({power, i});
        }

        int ans = 0;
        while (k--) {
            auto it = pq.top();
            pq.pop();
            ans = it.second;
        }

        return ans;
    }
};