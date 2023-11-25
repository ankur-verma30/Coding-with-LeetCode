class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
         std::vector<int> result;

    for (int i = 0; i < words.size(); ++i) {
        const string& word = words[i];
        if (word.find(x) != string::npos) {
            result.push_back(i);
        }
    }

    return result;
    }
};