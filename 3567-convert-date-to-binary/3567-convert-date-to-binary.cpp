class Solution {
public:
    string ToBinary(int number) {
        string res;
        while (number != 1) {
            if (number % 2 == 0)
                res += '0';
            else
                res += '1';
            number = number / 2;
        }
        res += '1';
        reverse(res.begin(), res.end());

        return res;
    }
    string convertDateToBinary(string date) {
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);

        year = ToBinary(stoi(year));
        month = ToBinary(stoi(month));
        day = ToBinary(stoi(day));

        return year + '-' + month + '-' + day;
    }
};