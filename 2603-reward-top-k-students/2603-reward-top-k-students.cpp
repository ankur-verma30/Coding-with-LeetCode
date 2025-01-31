struct comparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second<b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id,
                            int k) {
        set<string> positive, negative;

        for (const auto word : positive_feedback)
            positive.insert(word);
        for (const auto word : negative_feedback)
            negative.insert(word);

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        for (int i = 0; i < report.size(); i++) {
            string word = report[i];
            int student = student_id[i];
            int count = 0;

            stringstream s(word);
            string str;
            while (s >> str) {
                if (positive.find(str) != positive.end())
                    count += 3;
                else if (negative.find(str) != negative.end())
                    count -= 1;
            }

            pq.push({count, student});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int id = temp.second;
            ans.push_back(id);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};