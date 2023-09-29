class Solution {
public:
    bool isAnagram(string s, string t) {
    //    sort(s.begin(),s.end());
    //    sort(t.begin(),t.end());
    //    bool r;
    //    (s==t)? r= true: r= false;
    //    return r;

       //can be solved using hash table
         if(s.length()!=t.length())
       return false;

      bool r=false;
       int count=0;

       sort(s.begin(),s.end());
       sort(t.begin(),t.end());

       for(int i=0;i<s.length();i++){
           if(s[i]==t[i]){
               count+=1;
           }
           else{
               count+=0;
           }
       }
           if(count==s.length())
          r=true;
          else
          r=false;
     return r;
    }
};