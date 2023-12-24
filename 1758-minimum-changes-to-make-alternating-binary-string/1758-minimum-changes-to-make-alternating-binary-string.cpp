class Solution {
public:
    int minOperations(string s) {
        /*
     int count=0;

     for(int i=0;i<s.length();i++){
         if(s[i]-'0'==i%2)
         count++;
     }

     return min(count,(int)s.length()-count);
     */
     int count=0;
        
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                if(s[i-1]=='0'){
                    s[i]='1';
                    count++;
                }
                else if(s[i-1]=='1'){
                    s[i]='0';
                    count++;
                }
            }
        }
        return min(count,(int)s.length()-count);
    }
};