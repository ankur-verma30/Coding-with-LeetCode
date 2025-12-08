class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();

        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }

        return true;
    }

    string toBinary(int n) {
        if (n == 0)
            return "0";
        string s = "";
        while (n > 0) {
            s.push_back((n % 2) + '0');
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (isPalindrome(toBinary(nums[i]))) {
                ans[i] = 0;
                continue;
            }
            int val1 = INT_MAX, val2 = INT_MAX;
            for (int num = nums[i]; num <= 5000; num++) {
                if (isPalindrome(toBinary(num))) {
                    val1 = num - nums[i];
                    break;
                }
            }

            for (int num = nums[i]; num >=1; num--) {
                if (isPalindrome(toBinary(num))) {
                    val2 = nums[i]-num;
                    break;
                }
            }
            ans[i]=min(val1,val2);
        }

        return ans;
    }
};