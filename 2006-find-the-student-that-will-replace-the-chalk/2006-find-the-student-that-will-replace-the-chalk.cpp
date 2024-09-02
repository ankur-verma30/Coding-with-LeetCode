class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (auto& x : chalk)
            sum += x;

        long long rem = k % sum;

        for (int i = 0; i < chalk.size(); i++) {
            if (chalk[i] > rem)
                return i;
            else
                rem -= chalk[i];
        }

        return 0;
    }
};