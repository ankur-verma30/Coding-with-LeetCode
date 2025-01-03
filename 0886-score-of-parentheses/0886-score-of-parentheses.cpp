class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> scoreStack;
        for (char ch : s) {
            if (ch == '(') {
                scoreStack.push(score);
                score = 0;
            } else {
                score = scoreStack.top() + max(2 * score, 1);
                scoreStack.pop();
            }
        }

        return score;
    }
};