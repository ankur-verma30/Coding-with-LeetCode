class Solution {
public:
    bool judgeCircle(string moves) {
       int xMovement=0,yMovement=0;

       for(char move:moves){
        if(move=='U') yMovement++;
        if(move=='D') yMovement--;
        if(move=='R') xMovement++;
        if (move=='L') xMovement--;
       } 

       return xMovement==0 && yMovement==0;
    }
};