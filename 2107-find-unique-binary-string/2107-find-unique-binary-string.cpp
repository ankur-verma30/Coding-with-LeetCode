class Solution {
public:
    string NumberToBinary(int num, int length) {
        string str = "";

        while (num > 0) {
            if (num & 1)
                str += '1';
            else
                str += '0';
            num >>= 1;
        }
        while (str.length() < length)
            str += '0';
        reverse(str.begin(), str.end());
        return str;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int maxNum = (1 << n) - 1;
        unordered_set<string> isPresent(nums.begin(), nums.end());

        for (int i = 0; i <= maxNum; i++) {
            string str = NumberToBinary(i, n);
            if (isPresent.count(str) < 1)
                return str;
        }
        return "";
    }
};