class Solution {
public:
    string normalise(string res){
       unordered_map<char,char>mpp;

       char ch='a';
       for(auto c:res){
        if(!mpp.count(c)) mpp[c]=ch++;
       }
        
        for(auto &c:res) c=mpp[c];
        return res;
       
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        string newPattern=normalise(pattern);

        vector<string>res;
        for(const auto &word:words){
            string newWord=normalise(word);
            if(newWord==newPattern) res.push_back(word);
        }
        return res;
        
    }
};