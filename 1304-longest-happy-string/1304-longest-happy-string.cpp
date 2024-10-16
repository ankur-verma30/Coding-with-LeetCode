class Solution {
public:
  struct cmp {
    bool operator()(const pair<int, char>& a, const pair<int, char>& b) const {
        return a.first < b.first;
    }
};
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        if (a > 0)
            pq.push({a, 'a'});

        if (b > 0)
            pq.push({b, 'b'});

        if (c > 0)
            pq.push({c, 'c'});

        string res;
        while (!pq.empty()) {
            pair<int, char> start = pq.top();
            pq.pop();
            int n = res.length();
            char ch = start.second;
            int count = start.first;
            if (n >= 2 && res[n - 1] == ch && res[n - 2] == ch) {
                if (pq.empty())
                    break;
                pair<int, char> sec = pq.top();
                pq.pop();
                res += sec.second;
                sec.first--;
                if (sec.first > 0)
                    pq.push(sec);

            } else {
                res += start.second;
                start.first--;
            }
            if (start.first > 0)
                pq.push(start);
        }
        return res;
    }
};