class Solution {
public:
    string NewString(string& word, int k) {
        string str;
        for (int i = 0; i < word.length(); i++) {
            int temp = ((word[i] - 'a') + 1) % 26;
            char ch = temp + 'a';
            str += ch;
        }
        return str;
    }

    char kthCharacter(int k) {
        string word = "a";

        while (true) {
            string ans = NewString(word, k);
            word += ans;
            if (word.length() >= k) {
                return word[k - 1];
                break;
            } else
                NewString(word, k);
        }

        return '0';
    }
};