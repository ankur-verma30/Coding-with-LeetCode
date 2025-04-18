class Solution {
public:
    string countAndSay(int n) {
        string str = "1";

        for (int i = 1; i < n; i++) {
            int count = 0;
            char prev = str[0];
            string temp;
            for (int i = 0; i < str.length(); i++) {
                if (prev == str[i])
                    count++;
                else if (prev != str[i]) {
                    temp += to_string(count) + prev;
                    count = 1;
                    prev = str[i];
                }
            }
            temp += to_string(count) + prev;
            str = temp;
        }
        return str;
    }
};