class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> str1, str2;
        stringstream s(s1),st(s2);
        string word;

        while (s >> word)
            str1.push_back(word);

        while (st >> word)
            str2.push_back(word);

        int n1 = str1.size(), n2 = str2.size();
        if (n1 > n2) {
            swap(str1, str2);
            swap(n1, n2);
        }

        int first = 0, second = 0;

        while (first < n1 && (str1[first] == str2[first]))
            first++;
        while (second < str1.size() &&
               str1[str1.size() - second - 1] == str2[str2.size() - second - 1])
            second++;

        return first + second >= n1;
    }
};