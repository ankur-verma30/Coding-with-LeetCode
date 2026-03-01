class Solution {
public:
    string trimTrailingVowels(string s) {
        set<char>st{'a','i','e','o','u'};

        while(!s.empty() && st.count(s.back()) ){
            if(st.count(s.back())) s.pop_back();
        }

        return s;
    }
};