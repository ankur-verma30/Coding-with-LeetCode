class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char, char> m,n;

        if(s.length()!=t.length())
        return false;
        int len=s.length();

        for( int i=0 ; i<len; i++)
        {
            m[s[i]] = t[i];
            n[t[i]] = s[i];
        }
        for(int i=0 ; i<len; i++)
        {
          if((m[s[i]]!=t[i])|| (n[t[i]]!=s[i])){
                    return false;
                    break;
            }
        }
        
        return true;
    }
};