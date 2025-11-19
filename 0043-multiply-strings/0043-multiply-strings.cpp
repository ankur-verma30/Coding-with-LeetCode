class Solution {
public:

    string addString(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            ans += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        string ans = "0";

        for (int i = n1 - 1; i >= 0; i--) { // RIGHT to LEFT
            int carry = 0, val1 = num1[i] - '0';
            string temp;

            // shift zeros based on position
            temp.append(n1 - 1 - i, '0');

            for (int j = n2 - 1; j >= 0; j--) {
                int val2 = num2[j] - '0';
                int pro = val1 * val2 + carry;
                temp += (pro % 10) + '0';
                carry = pro / 10;
            }

            if (carry) temp += carry + '0';

            reverse(temp.begin(), temp.end());
            ans = addString(ans, temp);
        }

        return ans;
    }
};
