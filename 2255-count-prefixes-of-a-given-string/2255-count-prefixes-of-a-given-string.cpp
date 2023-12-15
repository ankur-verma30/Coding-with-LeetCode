class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
     int count =0;

     for(auto word:words){
     int len=word.length();
     auto subs=s.substr(0,len);
     if(word==subs)
     count++;
    }
     return count;
    }
};