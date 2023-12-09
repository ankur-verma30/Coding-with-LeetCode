class Solution {
public:
    char repeatedCharacter(string s) {
      unordered_set<char> st;
      char ch;

      for(int i=0;i<s.length();i++){
          if(st.count(s[i]))
          return s[i];
          else
          st.insert(s[i]);
      }  
      return ch;

    }
};