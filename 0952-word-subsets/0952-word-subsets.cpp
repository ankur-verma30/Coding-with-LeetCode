class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq1(26,0);

        for(const auto &word:words2){
            vector<int>freq(26,0);
            for(const auto ch:word){
                freq[ch-'a']++;
               freq1[ch-'a']=max(freq[ch-'a'],freq1[ch-'a']);
            }
        }


        vector<string>ans;

        for(const auto &word:words1){
            vector<int>freq2(26,0);
            for(const auto &ch:word){
                freq2[ch-'a']++;
            }
            bool isValid=true;
            for(int i=0;i<26;i++){
                if(freq1[i]>freq2[i] ){
                    isValid=false;
                    break;
                }
        }
                if(isValid) ans.push_back(word);
        }

        return ans;
    }
};