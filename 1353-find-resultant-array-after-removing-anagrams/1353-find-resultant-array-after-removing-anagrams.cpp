class Solution {
public:
    bool isAnagram(string &word1, string &word2){
        vector<int>word1Freq(26,0);
        vector<int>word2Freq(26,0);

        for(const auto &ch:word1) word1Freq[ch-'a']++;
        for(const auto &ch:word2) word2Freq[ch-'a']++;

        return word1Freq==word2Freq;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>ans;

        ans.push_back(words[0]);

        for(int i=1;i<n;i++){
            string word1=ans.back();
            string word2=words[i];
            if(!isAnagram(word1,word2)) ans.push_back(word2);
        }

        return ans;
    }
};