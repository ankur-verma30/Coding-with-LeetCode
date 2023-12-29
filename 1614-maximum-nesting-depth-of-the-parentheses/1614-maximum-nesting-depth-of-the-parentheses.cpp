class Solution {
public:
    int maxDepth(string s) {
     int count=0,Depth=0;

     for(int i=0;i<s.length();i++){
         if(s[i]=='(' ){
             count++;
             Depth=max(count,Depth);
         }
         else if(s[i]==')' && count>=1)
         count--;
     }   
     return Depth;
    }
};