class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for (int i = 0; i < details.size(); i++) {
            string word = details[i];
            string str = word.substr(11, 2);
            int val = convert(str);
            if (val > 60)
                count++;
        }

        return count;
    }

    int convert(string str) {
        int res = 0;
        int num1 = str[0] - '0';
        int num2 = str[1] - '0';

        res = num1 * 10 + num2;

        return res;
    }
};