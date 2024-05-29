class Solution {
public:
    // Function to add one to the binary string
    string AddOne(string s) {
        reverse(s.begin(), s.end());
        int carry = 1;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            int val = ch - '0';
            int sum = val + carry;
            int digit = sum % 2;
            s[i] = digit + '0';
            carry = sum / 2;
        }
        if (carry) {
            s.push_back('1');
        }
        reverse(s.begin(), s.end());
        return s;
    }

    // Function to remove trailing zeros from the binary string
    string RemoveZero(string s) {
        while (s.back() == '0') {
            count++;
            s.pop_back();
        }
        return s;
    }

    int count = 0;

    // Recursive function to simulate the steps
    void solve(string s) {
        if (s == "1") {
            return;
        }

        if (s.back() == '0') {
            s = RemoveZero(s);
        } else {
            s = AddOne(s);
            count++;
        }

        solve(s);
    }

    int numSteps(string s) {
        solve(s);
        return count;
    }
};
