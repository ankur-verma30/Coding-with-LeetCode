class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.size();
        int m=words.size();

        if(n==1) return true;

        unordered_map<int, int> charToIndex;
        for (int i = 0; i < n; i++)  charToIndex[order[i]] = i;
        
        for(int i=1;i<m;i++){
            string word1=words[i-1];
            string word2=words[i];
            bool flag=false;
            int index1=0,index2=0,w1=word1.length(),w2=word2.length();
            while(index1<w1 && index2<w2){
                if(word1[index1]==word2[index2]) continue;
                int pos1=charToIndex[word1[index1]];
                int pos2=charToIndex[word2[index2]];
                if(pos1>pos2) return false;
                else if(pos1<pos2){
                    flag=true;
                     break;
                }
                    index1++;
                    index2++;
            }
            if(!flag && index1!=w1) return false;
        }

        return true;
        
    }
};