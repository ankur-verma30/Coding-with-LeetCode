struct compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;

        for (const auto word : words)
            mpp[word]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, compare>
            pq;

        for (const auto& [word, freq] : mpp) {
            pq.push({freq, word});
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};