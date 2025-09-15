class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>words;
        string str="";
        for(int i=0;i<text.length();i++){
            if(text[i]==' '){
                words.push_back(str);
                str="";
            }
            str+=text[i];
        }

        words.push_back(str);

        unordered_set<char>st;
        for(const auto ch:brokenLetters) st.insert(ch);

        int count=0;
        for(const auto &word:words ){
            bool flag=true;
            for(const auto ch:word){
                if(st.count(ch)){
                    flag=false;
                    break;
                }
            }
            if(flag) count++;
        }

        return count;
    }
};