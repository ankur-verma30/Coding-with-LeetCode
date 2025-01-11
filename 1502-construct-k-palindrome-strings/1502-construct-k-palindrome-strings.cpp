class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();

        if(n<k) return false;

        unordered_map<char,int>freq;

        for(int i=0;i<n;i++) freq[s[i]]++;


        int oddCount=0;
        for(const auto &[element,count]:freq){
            if(count%2!=0) oddCount++; 
        }
        
        if(oddCount>k) return false;

        return true;

    }
};