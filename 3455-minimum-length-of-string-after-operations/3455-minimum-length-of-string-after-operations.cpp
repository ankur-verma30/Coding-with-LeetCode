class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mpp;
        int removal=0;

        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
            if(mpp[s[i]]==3) {
                removal+=2;
                mpp[s[i]]-=2;
            }
        }
        return (int)s.length()-removal;
    }
};