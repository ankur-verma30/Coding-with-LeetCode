class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < gifts.size(); i++)
            pq.push(gifts[i]);

        long long remaining = 0;
        while (k--) {
            int element = pq.top();
            pq.pop();
            int rem = sqrt(element);
            pq.push(rem);
        }

        while (!pq.empty()) {
            remaining += pq.top();
            pq.pop();
        }

        return remaining;
    }
};