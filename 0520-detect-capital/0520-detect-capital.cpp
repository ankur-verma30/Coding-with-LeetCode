class Solution {
public:
    bool detectCapitalUse(string word) {
       int len=word.length();
       bool flag=false,flag1=false,flag2=false;

       for(int i=0;i<len;i++){
           if(word[i]>=65 && word[i]<=90)
           flag=true;
           else{
               flag=false;
               break;
           }
       }

       if(flag==true)
       return true;

       for(int i=0;i<len;i++){
           if(word[i]>=97 && word[i]<=122)
           flag1=true;
           else{
               flag1=false;
               break;
           }
       }

       if(flag1==true)
       return true;

       if(word[0]>=65 && word[0]<=90){
            for(int i=1;i<len;i++){
                if(word[i]>=97 && word[i]<=122)
                    flag2=true;
                else{
                    flag2=false;
                    break;
                }
           }
        }
           if(flag2==true)
           return true;
           
    return false;
    }
};