class Solution {
public:
    int passThePillow(int n, int time) {
         int count=1, index=1;
        bool direction=true;
        while(count<=time)
        {
            if(index==n) direction=false;
            else if(index==1) direction=true;
            
            count++;
            
            if(direction)   index++;
            else  index--;
        }
        return index;
    }
};