class Solution {
public:
    string InvertString(string temp) {
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '0')
                temp[i] = '1';
            else
                temp[i] = '0';
        }

        return temp;
    }
    string Concat(string str) {
        string newStr = str;
        newStr += '1';
        string temp = InvertString(str);
        reverse(temp.begin(), temp.end());
        newStr += temp;

        return newStr;
    }

    char findKthBit(int n, int k) {
        string str = "0";
        for (int i = 1; i <= n; i++) {
            string temp = Concat(str);
            str = temp;
        }

        char ans;
        for (int i = 0; i < k; i++)
            ans = str[i];

        return ans;
    }
};