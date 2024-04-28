class Solution {
public:
    int numberOfSpecialChars(string word) {
         int ans = 0;
        unordered_map<char,int> m;
        
        for(auto ch : word) {
            m[ch]++; 
        }

        for(char ch='a'; ch<='z'; ch++) {
            if(m[ch] > 0 && m[toupper(ch)] > 0) { 
                ans++; 
            }
        }
     return ans;
    }
};