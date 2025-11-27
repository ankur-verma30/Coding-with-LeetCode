class Solution {
public:
    string reverseVowels(string s) {
        set<char> st = {'a','A','e','E','i','I','o','O','u','U'};

        int i = 0, j = s.length() - 1;

        while(i < j) {

            while(i < j && !st.count(s[i])) i++;
            while(i < j && !st.count(s[j])) j--;

            swap(s[i], s[j]);

            i++;
            j--;
        }

        return s;
    }
};
