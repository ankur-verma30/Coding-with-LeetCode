class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>count;
        int changes=s.length();

        for(int i=0;i<s.length();i++)
        count[s[i]]++;


        for(int i=0;i<t.length();i++){
            if(count.find(t[i])!=count.end()  && count[t[i]] > 0){
                changes--;
                count[t[i]]--;
            }
        }
        return changes;
    }
};