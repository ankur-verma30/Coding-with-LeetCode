class Solution {
public:
    bool isSame(char ch,string &s,int k,int index){
        for(int i=index;i<index+k;i++){
            if(ch!=s[i]) return false;
        }
        return true;
    }
    bool hasSpecialSubstring(string s, int k) {
      int n=s.length();

        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isSame(ch,s,k,i)){
                bool beforeDifferent = (i == 0 || s[i - 1] != ch);
                bool afterDifferent = (i + k >= n || s[i + k] != ch);
            if (beforeDifferent && afterDifferent) return true;
            }  
        }

        return false;
    }
};