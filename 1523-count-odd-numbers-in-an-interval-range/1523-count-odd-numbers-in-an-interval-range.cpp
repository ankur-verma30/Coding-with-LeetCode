class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        if((high-low+1)%2==0)
        return (high-low+1)/2;
        else{         //can be optimised
       while(low<=high){
            if(low%2!=0)
           {
               count++;
               low+=2;
           }
            else
            low++;
      
        }
        }
        return count;
    }
};