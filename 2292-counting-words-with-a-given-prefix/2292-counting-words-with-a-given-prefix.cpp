class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0,n=pref.length();

        for(const auto word:words){
            if(((int)word.length()>=n) && (pref==word.substr(0,n))) count++;
        }

        return count;
    }
};