class Solution {
public:
    string getHappyString(int n, int k) {
        string result;
        int count = 0;
        string current = "";
        backtrack(n, k, current, count, result);
        return result;
    }
    
    bool backtrack(int n, int k, string& current, int &count, string &result) {
        if (current.size() == n) {
            count++;
            if (count == k) {
                result = current;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!current.empty() && current.back() == ch) continue;
            current += ch;
            if (backtrack(n, k, current, count, result)) return true;
            current.pop_back();
        }
        return false;
    }
};