class Solution {
public:
    bool faultyCheck(string& s, int faultyLeft, int faultyRight) {
        int n = s.length();

        // Delete faultyLeft
        bool isLeftFaulty = false;
        int left = faultyLeft, right = faultyRight;

        while (left < right) {
            if (left == faultyLeft)
                left++;
            else if (s[left] != s[right]){
                isLeftFaulty = true;
                break;
            }
            else {
                left++;
                right--;
            }
        }

        if (!isLeftFaulty)
            return true;

        // Delete faultyRight
        bool isRightFaulty = false;
        left = faultyLeft;
        right = faultyRight;

        while (left < right) {
            if (right == faultyRight)
                right--;
            else if (s[left] != s[right]){
                isRightFaulty = true;
                break;
            }
            else {
                left++;
                right--;
            }
        }

        return !isRightFaulty;
    }

    bool validPalindrome(string s) {
        int n = s.length();

        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                return faultyCheck(s, i, n - 1 - i);
            }
        }

        return true;
    }
};