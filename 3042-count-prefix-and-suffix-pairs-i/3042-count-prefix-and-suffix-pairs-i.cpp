class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        int l0=words.size(),l1,l2;
        
        for(int i=0;i<l0-1;i++){
            string word1=words[i];
            l1=word1.length();  
            for(int j=i+1;j<l0;j++){
                  bool prefix=false,suffix=false;
                string word2=words[j];
                l2=word2.length();
                
                if(l2>=l1){
                 if(word1==word2.substr(0,l1)) prefix=true;
                    if(word1==word2.substr(l2-l1)) suffix=true;
                    if(prefix && suffix) count++;
                }
                
            }
             
        }
        return count;
    }
};