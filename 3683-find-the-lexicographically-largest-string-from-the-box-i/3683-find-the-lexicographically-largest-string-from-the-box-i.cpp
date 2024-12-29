class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        string str="";
        int n=word.size();
        int wordCount=n-numFriends+1;

        for(int i=0;i<n;i++){
            string temp=word.substr(i,wordCount);
            str=max(str,temp);
        }

        return str;
    }
};