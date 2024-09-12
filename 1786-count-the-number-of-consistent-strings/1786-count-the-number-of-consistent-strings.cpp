class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st(allowed.begin(),allowed.end());
        int count=0;

        for(int i=0;i<words.size();i++){
            string str=words[i];
            bool isfound=true;
            for(int i=0;i<str.length();i++){
                if(st.find(str[i])==st.end()) isfound=false;
            }
            if(isfound) count++;
        }

        return count;
    }
};