class Solution {
public:
    string convert(int num) {
        string ans;
        while (num != 0) {
            int rem = num % 10;
            char ch = rem + '0';
            ans += ch;
            num = num / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<int> pq;
        vector<string> result;

        for (auto x : score) {
            pq.push(x);
        }
        unordered_map<int, int> mpp;

        int count = 1;
        while (!pq.empty()) {
            mpp[pq.top()] = count;
            pq.pop();
            count++;
        }

        for (int i = 0; i < n; i++) {
            if (mpp[score[i]] == 1)
                result.push_back("Gold Medal");
            if (mpp[score[i]] == 2)
                result.push_back("Silver Medal");
            if (mpp[score[i]] == 3)
                result.push_back("Bronze Medal");
            if (mpp[score[i]] > 3) {
                int val = mpp[score[i]];
                string temp = convert(val);
                result.push_back(temp);
            }
        }
        return result;
    }
};