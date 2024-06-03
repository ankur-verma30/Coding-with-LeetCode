class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;

        while(i<(int)s.length() && j<(int)t.length()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else i++;
        }

        return ((int)t.length()-j);
        
    }
};