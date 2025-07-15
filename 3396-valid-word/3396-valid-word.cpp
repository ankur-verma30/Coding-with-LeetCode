class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;
        unordered_set<char> st{'@', '#', '$'};

        bool isVowel = false, isConsonant = false, isDigit = false,
             isLower = false, isUpper = false;

        for (const auto it : word) {
            if (st.count(it))
                return false;
            else if (isalpha(it)){
                if (it == 'a' || it == 'e' || it == 'i' || it == 'o' ||
                    it == 'u') {
                    isVowel = true;
                    isLower = true;
                }
                else if (it == 'A' || it == 'E' || it == 'I' || it == 'O' ||
                    it == 'U') {
                    isVowel = true;
                    isUpper = true;
                } 
                else isConsonant = true;
            }
                else if (it >= '0' || it <= '9') isDigit = true;
        }
        int temp = isDigit || isLower || isUpper;
        return temp && isVowel && isConsonant;
    }
};