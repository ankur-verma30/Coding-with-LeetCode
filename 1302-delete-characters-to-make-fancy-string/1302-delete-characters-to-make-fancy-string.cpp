class Solution {
public:
    string makeFancyString(string s) {

        if(s.length()<3) return s;
        string str = "";
        
        int count = 1;
        char prev = s[0];
        str += prev;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == prev) {
                count++;
                if (count <= 2)
                    str += s[i];
                else
                    continue;
            } else {
                str += s[i];
                prev = s[i];
                count = 1;
            }
        }
        return str;
    }
};