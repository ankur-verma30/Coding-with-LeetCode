class Solution {
public:
    int strStr(string haystack, string needle) {
          int n=haystack.size(),m=needle.size();
       
        if(haystack==needle)
        return 0;

        if(n<m)
        return -1;

        string sub="";
        for(int i=0;i<n;i++){
            sub=haystack.substr(i,m);
            if(sub==needle)
            return i;

        }
        return -1;
        
    }
};