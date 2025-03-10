class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);

        deque<int> dq;

        sort(deck.begin(), deck.end());
        for (int i = 0; i < n; i++) {
            dq.push_back(i);
        }

        for (int card : deck) {
            int index = dq.front();
            dq.pop_front();
            ans[index] = card;

            if (!dq.empty()) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        return ans;
    }
};