class Solution {
public:
    string findValidPair(string s) {
        string ans;
        unordered_map<char,int>mpp;

        for(const auto &ch:s){
            mpp[ch]++;
        }

        for(int i=1;i<s.length();i++){
            char ch1=s[i-1];
            char ch2=s[i];
            
            if(ch1!=ch2){
                int intCh1 = ch1 - '0'; 
                int intCh2 = ch2 - '0';
                if(mpp[ch1]==intCh1 && mpp[ch2]==intCh2){
                    ans+=ch1;
                    ans+=ch2;
                    return ans;
                }
            }
        }
        return "";

    
    
    }
};