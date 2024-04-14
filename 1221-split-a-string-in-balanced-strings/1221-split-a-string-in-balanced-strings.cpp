class Solution {
public:
    int balancedStringSplit(string s) {
        int len=s.length();
        int pointer=0;

        int Lcount=0,Rcount=0,TotalCount=0;

        while(pointer<len){

              if(s[pointer]=='L') Lcount++;
            if(s[pointer]=='R') Rcount++;

            if(Lcount==Rcount){
                TotalCount++;
                Lcount=0;
                Rcount=0;
                pointer++;
                
            }
            else pointer++;
        }

        return TotalCount;
    }
};