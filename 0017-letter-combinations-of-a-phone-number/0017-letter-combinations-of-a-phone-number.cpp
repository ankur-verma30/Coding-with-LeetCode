class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty())  return {};
        

        unordered_map<char, string> mpp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res = {""}; 

        for (char digit : digits) {
            vector<string> temp;
            string letters = mpp[digit];
            for (const string& comb : res) {
                for (char letter : letters) {
                    temp.push_back(comb + letter);
                }
            }
            res = move(temp); 
        }

        return res;
    }
};