class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        int size = group.size();

        vector<vector<int>> arr(size + 1);

        for (int i = 0; i < size; i++) {
            int val = group[i];
            arr[val].push_back(i);
        }

        vector<vector<int>> res;

        for (int i = 1; i <= arr.size() - 1; i++) {
            vector<int> temp;
            int count = 0;
            for (int j = 0; j < arr[i].size(); j++) {
                temp.push_back(arr[i][j]);
                count++;
                if (count == i) {
                    count = 0;
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }

        return res;
    }
};