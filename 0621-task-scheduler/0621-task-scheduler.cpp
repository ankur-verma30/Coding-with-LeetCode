class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        priority_queue<int> pq;

        for (const auto& ch : tasks)
            mpp[ch - 'A']++;

        for (const auto& [ch, freq] : mpp)
            pq.push(freq);

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for (const auto& num : temp)
                if (num > 0)
                    pq.push(num);
            if (pq.empty())
                time += temp.size();
            else
                time += n + 1;
        }

        return time;
    }
};