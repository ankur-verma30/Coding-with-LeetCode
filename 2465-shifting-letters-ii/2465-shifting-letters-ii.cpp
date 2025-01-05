class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> prefix(n + 1, 0);

        for (const auto query : shifts) {
            int start = query[0];
            int end = query[1];
            int direction = query[2];

            if (direction == 0) {
                prefix[start] += -1;
                prefix[end + 1] += 1;
            } else {
                prefix[start] += 1;
                prefix[end + 1] += -1;
            }
        }

        string str = s;
        int shiftSum = 0;
        for (int i = 0; i < n; i++) {
            shiftSum =(shiftSum+prefix[i])%26;
            if(shiftSum<0) shiftSum+=26;
            str[i] = 'a' + ((str[i] - 'a') + shiftSum) % 26;
        }

        return str;
    }
};