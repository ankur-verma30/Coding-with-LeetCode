class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxLen = 0;

        for (int i = 0; i < sentences.size(); i++) {
            string word = sentences[i];
            int count=1;
            for(int i=0;i<word.length();i++){
                if(word[i]==' ') count++;
            }
            maxLen=max(count,maxLen);
        }

        return maxLen;
    }
};