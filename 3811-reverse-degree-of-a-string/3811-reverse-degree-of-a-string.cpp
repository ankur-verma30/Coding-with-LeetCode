class Solution {
public:
    int reverseDegree(string s) {
       vector<int>letters(26,0); 
        int counter=26;
        
        for(int i=0;i<26;i++){
            letters[i]=counter--;
        }
        
        int total=0;
        for(int i=0;i<s.length();i++){
            int val=letters[s[i]-'a'];
            total+=(val*(i+1));
        }

        return total;
    }
};