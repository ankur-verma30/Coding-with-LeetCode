class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;


        for(const auto &str:strs){
            string word=str;
            sort(word.begin(),word.end());
            mpp[word].push_back(str);

        }

        vector<vector<string>>res;
        for(const auto &[word,anagrams]:mpp){
            res.push_back(anagrams);
        }

        return res;
    }
};