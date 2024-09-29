class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int subStringCount = 0;
        int n = word.length();
        set<char> st;

        for (auto& ch : word) {
            if (ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u')
                st.insert(ch);
        }
        if (st.size() < 5)
            return 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            int count = 0;
            for (int j = i; j < n; j++) {
                char ch = word[j];
                if (ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' ||
                    ch == 'u')
                    mpp[ch]++;
                else
                    count++;
                if (count == k && mpp.size() == 5)
                    subStringCount++;
            }
        }
        return subStringCount;
    }
};