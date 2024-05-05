class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

    bool hasVowel = false;
    bool hasConsonant = false;
        bool isUpper=false;
        bool isLower=false;
        bool isDigit=false;
        bool symbol=true;

    for (char c : word) {
        if (isalpha(c)) { // Check if character is a letter
            if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u'){
                    hasVowel = true;
                isLower=true;
            }
          
           if (toupper(c) == 'A' || toupper(c) == 'E' || toupper(c) == 'I' || toupper(c) == 'O' || toupper(c) == 'U'){
                hasVowel = true;
                isUpper=true;
          }
            else
                hasConsonant = true;
        }
        if(c-'0'>=48 && c-'0'<=57) isDigit=true;
        
        if(c=='$' || c=='@' || c=='#') symbol=false;
        
    }
        
        bool mid=isUpper || isLower || isDigit;
        
        

    return hasVowel && hasConsonant && mid && symbol;
    }
};