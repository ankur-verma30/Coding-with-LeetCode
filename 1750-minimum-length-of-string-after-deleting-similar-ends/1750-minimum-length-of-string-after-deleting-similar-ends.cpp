class Solution {
public:
    int minimumLength(string s) {
         int len = s.length();

        if (len <= 1) return len; 
        
        int low = 0, high = len - 1;

        while (low < high && s[low] == s[high]) {
            char ch = s[low];
            while (low <= high && s[low] == ch) low++;
            while (high >= low && s[high] == ch) high--;
        }

        return max(0, high - low + 1);
    
    }
};