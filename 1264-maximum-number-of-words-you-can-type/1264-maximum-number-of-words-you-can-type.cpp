class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st;
        for(const auto ch:brokenLetters) st.insert(ch);

        int count=0;
        bool isBroken=false;
        for(int i=0;i<text.length();i++){
           if(text[i]!=' '){
            if(st.count(text[i])) isBroken=true;
           }
           else{
            if(!isBroken) count++;
            isBroken=false;
           }
        }
        
        if(!isBroken) count++;
        return count;
    }
};