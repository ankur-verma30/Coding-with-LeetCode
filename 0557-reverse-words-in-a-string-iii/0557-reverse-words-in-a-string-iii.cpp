class Solution {
public:
    string reverseWords(string s) {
        int len=s.length(),right=0;

        string ans="",word="";

        while(right<len){
            if(s[right]!=' ') word+=s[right];
            if(s[right]==' '){
                reverse(word.begin(),word.end());
                ans+=word+' ';
                word="";
            }
            right++;
        }
        reverse(word.begin(),word.end());
        return ans+word; 
    }
};