class Solution {
public:
    string smallestNumber(string pattern) {
         string result;
         stack<int> numStack;

    for (int i = 0; i <= pattern.size(); i++) {
      numStack.push(i + 1);
      if (i == pattern.size() || pattern[i] == 'I') {
        while (!numStack.empty()) {
          result += to_string(numStack.top());
          numStack.pop();
        }
      }
    }

    return result;
    }
};