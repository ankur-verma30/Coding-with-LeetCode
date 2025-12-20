class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size(), col = strs[0].length(), count = 0;

        for (int j = 0; j < col; j++) {
            char prev = 'a';
            for (int i = 0; i < row; i++) {
                if (strs[i][j] < prev) {
                    count++;
                    break;
                }
                prev = strs[i][j];
            }
        }

        return count;
    }
};