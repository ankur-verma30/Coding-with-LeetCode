class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int fuel=0, count=0;
        while(mainTank >0 && additionalTank >0){
            fuel+=1;
            mainTank-=1;
            count++;
            if(count==5){
                count=0;
                additionalTank-=1;
                mainTank+=1;
            }
        }
    fuel+=mainTank;
    return fuel*10;
    }
}; 