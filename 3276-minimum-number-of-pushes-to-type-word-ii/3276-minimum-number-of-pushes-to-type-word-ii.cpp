class Solution {
public:
 
    int minimumPushes(string word) {

        unordered_map<char, int> wordCount;
        vector< int> words;

        for (auto& x : word)
            wordCount[x]++;

        for (auto& x : wordCount)  words.push_back(x.second);
        

        sort(words.rbegin(), words.rend());

        int i = 1, count = 1, minpush = 0;

        for (auto x : words) {
            if (count > 8) {
                count = 1;
                i++;
            }
            minpush += (x * i);
            count++;
        }
        return minpush;
    }
};