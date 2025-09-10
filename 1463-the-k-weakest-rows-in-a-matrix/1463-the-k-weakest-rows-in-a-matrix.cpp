class Solution {
    struct Compare{// {count, index}
                   bool operator()(pair<int, int>& a, pair<int, int>& b){
                       if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
}
;

public:
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int row = mat.size();
    int col = mat[0].size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    for (int i = 0; i < row; i++) {
        int count = 0;
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 1)
                count++;
        }
        pq.push({count, i});
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ans;

    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        ans.push_back(temp.second);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
}
;