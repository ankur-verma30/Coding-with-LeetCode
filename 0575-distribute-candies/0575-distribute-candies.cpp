class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> candy;
        int result=0;
       
        int len=candyType.size();
       for(auto x: candyType)
         candy.insert(x);

          int Csize=candy.size();

         if(Csize>len/2)
             result=len/2;
         else if(Csize==len/2)
             result=len/2;
             else
             return Csize;

         return result;  
    }
};