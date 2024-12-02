class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int len = searchWord.length();
        stringstream s(sentence);

        string word;

        int count = 0, ans = -1;

        while (s >> word) {
            if (word.length() >= len) {
                string str = word.substr(0, len);
                if (str == searchWord) {
                    ans = count+1;
                    break;
                }
            }
            count++;
        }

        return ans;
    }
};