class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();
        int maxIndex = n - 1, index1 = -1, index2 = -1;
        int maxDigit = str[n - 1] - '0';

        for (int i = n - 2; i >= 0; i--) {
            int currentDigit = str[i] - '0';
            if (currentDigit > maxDigit) {
                maxIndex = i;
                maxDigit = currentDigit;
            } else if (currentDigit < maxDigit) {
                index1 = i;
                index2 = maxIndex;
            }
        }

        if (index1 != -1)
            swap(str[index1], str[index2]);

        return stoi(str);
    }
};