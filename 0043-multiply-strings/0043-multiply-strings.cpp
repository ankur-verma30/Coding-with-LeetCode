class Solution {
public:
    string AddTwoString(string& ans, string str) {
        if (ans.empty())
            return str;
        int n1 = ans.length(), n2 = str.length();
        string res;
        int i = n1 - 1, j = n2 - 1, carry = 0, sum = 0, rem = 0;
        while (i >= 0 && j >= 0) {
            int val1 = ans[i] - '0';
            int val2 = str[j] - '0';
            sum = val1 + val2 + carry;
            rem = sum % 10;
            res += to_string(rem);
            carry = sum / 10;
            i--;
            j--;
        }

        while (i >= 0) {
            sum = (ans[i] - '0') + carry;
            rem = sum % 10;
            res += to_string(rem);
            carry = sum / 10;
            i--;
        }

        while (j >= 0) {
            sum = (str[j] - '0') + carry;
            rem = sum % 10;
            res += to_string(rem);
            carry = sum / 10;
            j--;
        }

        if (carry == 1)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }

    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.length(), n2 = num2.length();

        if (n1 < n2) {
            swap(num1, num2);
            swap(n1, n2);
        }

        string ans;
        int count = 0, carry = 0;

        for (int i = n2 - 1; i >= 0; i--) {
            int multiplier = num2[i] - '0', carry = 0;
            string str;
            for (int j = n1 - 1; j >= 0; j--) {
                int multiplicand = num1[j] - '0';
                int product = multiplier * multiplicand + carry;
                int rem = product % 10;
                carry = product / 10;
                str += to_string(rem);
            }
            int temp = count;
            if (carry != 0)
                str += to_string(carry);
            reverse(str.begin(), str.end());
            while (temp--)
                str += '0';
            count++;
            ans = AddTwoString(ans, str);
        }

        if (carry != 0)
            ans = to_string(carry) + ans;
        return ans;
    }
};