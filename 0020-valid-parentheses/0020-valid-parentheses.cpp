class Solution {
public:
    bool isValid(string s) {
          stack<char> stk;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false; // No matching opening bracket found
                }
                char top = stk.top();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                    stk.pop();
                } else {
                    return false; // Mismatched brackets
                }
            }
        }

        return stk.empty(); // Check if there are any unmatched opening brackets left
    }
};